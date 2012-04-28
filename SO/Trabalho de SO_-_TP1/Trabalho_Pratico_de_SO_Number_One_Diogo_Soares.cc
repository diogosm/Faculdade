/*	Universidade Federal do Amazonas
 * 	Departamento de Ciência da Computação
 * 	TP1_Sistemas_Operacionais
 * 	Alunos: Cássio de Paula, Diogo Soares, Paulo Leite
 */

#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#define MAX 300
#define TRUE 1
#define TEST(a,b) printf("o valor de a é b\n",a) 


pthread_t processos[MAX];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int SALDO = 0;

typedef struct{
	int procId;	//identificação do processo (1..n)
	int valor;	//valor numérico que diz o quanto deve ser sacado ou depositado em um processo k.
	int tipo;	//o tipo do processo. 1 = deposito, 2 = saque, 3 = consulta
} PROC;

PROC procs[MAX];


void initStruct(){
	int i = 0;

	while (i < MAX) {
		procs[i].procId = 0;
		procs[i].valor = 0;
		procs[i].tipo = 0;
		i++;
	}
}


void showStruct(){
	int i = 0;
	
	while (i < MAX) {
		printf("\nO struct na posicão %d tem os valores de: id = %d valor = %d e tipo = %d", i, procs[i].procId, procs[i].valor, procs[i].tipo);
		i++;
	}
	printf("\n");
}


void lerArquivo(FILE *fp){
	int i = 0;
	char proc_s[10];
	char tipo[10];

	while ( i < MAX && (!feof(fp))) {
	
		fscanf(fp, "%s %d %s %d ", proc_s, &procs[i].procId, tipo, &procs[i].valor);
		
		if ( (strcmp(tipo, "consulta")) == 0 ){
			procs[i].tipo = 3;
		}
		if ( (strcmp(tipo, "deposito")) == 0 ){
			procs[i].tipo = 1;
		}
		if ( (strcmp(tipo, "saque")) == 0 ){
			procs[i].tipo = 2;
		}
		i++;
	}		
}


void *consultaConta(void *arg){

	long offset = (long)arg;
	
	sleep(5);
	printf("Processo %ld de consulta criado\n", (offset+1));
	printf("Processo %ld de consulta. Saldo atual é de: %d\n", (offset+1), SALDO);

	pthread_exit((void*) 0);
}


void *saqueConta(void *arg){

	long offset = (long)arg;
	int used = 0;
	
	printf("Processo %ld de saque criado. Saque (%d)\n", (offset+1), procs[offset].valor);
	while( used == 0 ) {
		sleep(5);
		if ( pthread_mutex_trylock(&mutex) == 0 ) {
			
			//pthread_mutex_lock(&mutex);
			
			SALDO = SALDO - (int)procs[offset].valor;
			printf("Processo %ld de saque acessa região crítica - saca (%d)\n", (offset+1), procs[offset].valor);
			pthread_mutex_unlock(&mutex);
			used += 1;
		}
		else { 
			printf("Processo %ld de saque bloqueado.\n", (offset+1));
		}
	}
	printf("Processo %ld de saque sai da região crítica.\n", (offset+1));
	pthread_exit((void*) 0);
}	


void *depositoConta(void *arg){

	long offset = (long)arg;
	int used = 0;
	printf("Processo %ld de deposito criado. deposito (%d)\n", (offset+1), procs[offset].valor);
	

	while( used == 0 ) {
		
		if ( pthread_mutex_trylock(&mutex) == 0 ) {
			
				
					
			SALDO = SALDO + (int)procs[offset].valor;
			printf("Processo %ld de deposito acessou região crítica - deposita (%d)\n", (offset+1), procs[offset].valor);
			sleep(1);
			pthread_mutex_unlock(&mutex);
			used += 1;
		}
		else {
			printf("Processo %ld de deposito bloqueado.\n", (offset+1));
			sleep(4);
		}
	}
	printf("Processo %ld de deposito sai da região crítica.\n", (offset+1));
	pthread_exit((void*) 0);
}


int main(){

	FILE *in;
	int j;
	void *status;

	
	if ( (in = fopen("in2.txt", "r")) == NULL ) {
		printf("\nArquivo de entrada inexistente! \nTente novamente!\n\n");
		exit(1);
	}

	pthread_mutex_init(&mutex, NULL);
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

	initStruct();
	lerArquivo(in);
		
	for(j = 0; (j<MAX && (procs[j].tipo != 0)); j++){
		if ( procs[j].tipo == 1 ) {
			pthread_create(&processos[j], &attr, depositoConta, (void *)j);
		}
		else {
			if ( procs[j].tipo == 2 ) {
				pthread_create(&processos[j], &attr, saqueConta, (void *)j);
			}
			else {
				pthread_create(&processos[j], &attr, consultaConta, (void *)j);
			}
		}
	}

	pthread_attr_destroy(&attr);

	for(j = 0; (j<MAX && (procs[j].tipo != 0)); j++){
		pthread_join(processos[j], &status);
	}	

	printf("\n\n|| *** || O saldo é : %d || *** ||\n", SALDO);

return 0;
}

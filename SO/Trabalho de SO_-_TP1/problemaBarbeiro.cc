/*	Universidade Federal do Amazonas
 * 	Departamento de Ciência da Computação
 * 	TP1_Sistemas_Operacionais
 * 	Alunos: Cássio de Paula, Diogo Soares, Paulo Leite
 */

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <list>

int NUM_CLIENTES;
int NUM_CADEIRAS;
int NUM_BARBEIROS;

using namespace std;

list <int> listaCliente;

sem_t semClienteEntra;		//semaforos contadores
sem_t semClienteAtende;
sem_t semBarbeiro;

pthread_mutex_t mutex_bloqueia;

pthread_mutex_t bloqueia;

void *barbeiro(void *arg){
int idb = *(int*)(arg);    //numero do processo barbeiro
int idc;				   //numero do processo cliente

	/* Barbeiro dormindo */
	printf("Barbeiro %d dormindo.\n", idb);

	while(1){
		/* Barbeiro aguarda pelo cliente */
		sem_wait(&semClienteAtende);				//espera aqui até um processo cliente aparecer!

		pthread_mutex_lock(&bloqueia);
			idc = listaCliente.front();
			listaCliente.pop_front();
		pthread_mutex_unlock(&bloqueia);
		
		/*Libera a cadeira do cliente*/
		sem_post(&semClienteEntra);

		printf("Cliente %d acorda Barbeiro %d\n", idc, idb);
		/* Barbeiro acorda */
		printf("Barbeiro %d atendendo cliente %d.\n", idb, idc);
		sleep(5);
		printf("Cliente %d vai embora com cabelo cortado\n", idc);
		printf("Barbeiro %d volta a dormir.\n", idb);
	}
}

void *cliente(void *arg){
	int id = *((int*) arg);

	printf("Cliente %d chegou.\n",id);
	
	/*Tenta entrar na lista de espera da barbearia*/
	if(sem_trywait(&semClienteEntra) == 0){

		printf("cliente %d na cadeira do barbeiro.\n",id);

		/* Coloca o cliente na fila para ser atendido*/
		pthread_mutex_unlock(&bloqueia);
			listaCliente.push_back(id);
		pthread_mutex_unlock(&bloqueia);

		/*Avisa as thread Barbeiro que tem cliente*/
		sem_post(&semClienteAtende);
	} else {
		/* Buffer de espera para clientes cheio */
		printf("Barbearia lotada, cliente %d vai embora.\n", id);
	}
}		

int main(int argc, char **argv){
	pthread_t thr_clientes[NUM_CLIENTES], thr_barbeiro[NUM_BARBEIROS]; //vetor de threads p/ barbeiro e clientes
	int i;
	
	NUM_CLIENTES = atoi(argv[1]);
	NUM_CADEIRAS = atoi(argv[2]);
	NUM_BARBEIROS = atoi(argv[3]);

	/* Inicialização das pthreads */
	sem_init(&semClienteEntra, 0, NUM_CADEIRAS);
	sem_init(&semClienteAtende, 0, 0);
	sem_init(&semBarbeiro, 0, NUM_BARBEIROS);
	pthread_mutex_init(&bloqueia, NULL); //

	/* Criação das threads de barbeiros */
	for(i = 0; i < NUM_BARBEIROS; i++){
		pthread_create(&thr_barbeiro[i], NULL, barbeiro, (void*) &i);
		sleep(1);
	}

	/* Criação das threads de clientes */
	for(i = 0; i < NUM_CLIENTES; i++){
		pthread_create(&thr_clientes[i], NULL, cliente, (void*) &i);
		sleep(1);
	}

	/* Criação das threads de clientes */
	for(i = 0; i < NUM_BARBEIROS; i++){
		pthread_join(thr_barbeiro[i], NULL);
	}	
	/* Espera todas as threads de clientes terminarem a execução */

	return 0;
}

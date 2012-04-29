/*DIOGO SOARES MOREIRA -- 20810205
  Universidade Federal do Amazonas (UFAM) 
  Bacharelando em Ciência da Computação
  Lista 1 -- UFC -- questão 1 -- registro de matricula
*/

#include<locale.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define MAX 50

struct infos{
	char matricula[9];
	char data_nascimento[12];
	double nota1;
	double nota2;
	double nota3;
} infos_lista[MAX];




void iniciaLista(void){
	int i=0;

while(i<MAX){
	infos_lista[i].matricula[0] = '\0';
	i++;
}
}



int estah_cheia(){
	int i;


for(i=0; infos_lista[i].matricula[0] && i<MAX; i++)


if(i==MAX){
return -1;
}


return i;
}








void inserir(){
	int espaco = estah_cheia();
if(espaco == -1){
	printf("\nLista_cheia!!!");
	return;
	}

printf("\nDigite a matricula do aluno: ");
scanf("%s", infos_lista[espaco].matricula);
printf("\nDigite a data de nascimento: ");
scanf("%s", infos_lista[espaco].data_nascimento);
printf("\nDigite a primeira nota: ");
scanf("%lf", &infos_lista[espaco].nota1);
printf("\nDigite a segunda nota: ");
scanf("%lf", &infos_lista[espaco].nota2);
printf("\nDigite a terceira nota: ");
scanf("%lf", &infos_lista[espaco].nota3);
}






int menu(void){

	int x;


printf("\t\t\t\t::Menu do Programa::\n");
printf("\t\t\t\t(1) Inserir\n");
printf("\t\t\t\t(2) Mostrar\n");
printf("\t\t\t\t(3) Sair\n");

printf("\t\t\t\tDigite a sua opção:  ");
scanf("%d", &x);

return x;
}




void mostrar(){
	int i;
	

if(infos_lista[0].matricula[0] == '\0'){
			printf("\nLista Vazia!!");
			}


for(i=0; i<MAX; ++i){
	if(infos_lista[i].matricula[0]){
		printf("\n%s", infos_lista[i].matricula);
		printf("\n%s", infos_lista[i].data_nascimento);
		printf("\n%lf", infos_lista[i].nota1);
		printf("\n%lf", infos_lista[i].nota2);
		printf("\n%lf", infos_lista[i].nota3);
		printf("\n\n");  
		}
}
printf("\n\n");
}		





void ordenaStruct(){

	int i;
	

if(infos_lista[0].matricula[0] == '\0'){
			printf("\nLista Vazia!!");
			}


for(i=0; i<MAX; ++i){
	if(infos_lista[i].matricula[0]){
		












int main(void){

	int escolha;
iniciaLista();	
printf("\n");

printf("\t\t\t\t");


					/*área do código que mostra a hora atual.*/
struct tm *p;
time_t lt;
lt = time(NULL);
p = gmtime(&lt);
printf(asctime(p));



printf("\n");

for(;;){
	escolha = menu();
	switch(escolha){	
		case 1:
			inserir();
			break;
		case 2:
			mostrar();
			break;
		case 3:
			exit(0);		
		}
}

printf("\n");


return 0;
}


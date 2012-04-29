#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define MAX 100



typedef struct{
	char nome[50];
	int id;
} tipoDados;



typedef struct{
	tipoDados vet[MAX];
	int nelem;
} tipoLista;




void iniciar_lista(tipoLista *L){
	(*L).nelem = 0;  //ou L->nelem
}




void inserir_lista(tipoLista *L){

	register int i;

	i = L->nelem;

if(i>=MAX){
	printf("\nLista cheia!!");
}


printf("\nInsira o nome: ");
scanf("%s", L->vet[i].nome);
printf("\nInsira a idade: ");
scanf("%d", &L->vet[i].id);

L->nelem = L->nelem + 1;

printf("\n\n");
}




void mostrar_lista(tipoLista *L){
	register int x, i;

	x = L->nelem;

for(i=0; i<=x; i++){
	if(L->vet[i].nome[0] != '\0'){
		printf("\n%s", L->vet[i].nome);
		printf("\n%d", L->vet[i].id);
		}
	}
printf("\n\n");
}



void deletar_lista(tipoLista *L){
	register int t, x;
	char aux[20];
	t = L->nelem;
	int cont=0;

printf("\nInsira um nome: ");
scanf("%s", aux);

for(x=0; x<=t; x++){
	if(strcmp(L->vet[x].nome, aux)==0){
		L->vet[x].nome[0] = '\0';
		L->nelem = L->nelem - 1;
		cont ++;			
}
}

if(cont!=0){
	printf("\n(%d)Elemento(os) removidos com sucesso!!!\n", cont);
	}
else{
	printf("\nNão há registros com esse nome!!!\n");
}
}


void ordenar_lista(tipoLista *L){
	int i, j, menor;
	int exchange = 0;
	char *aux;
	tipoLista *LL;
	tipoDados D;
	LL = L;
for(i=0; i<LL->nelem-1; i++){
	aux = LL->vet[i].nome;
	menor = i;		
		for(j=i+1; j<LL->nelem; j++){
			if(strcmp(LL->vet[j].nome, aux)<0){				
				menor = j;
				exchange = 1;
			}
		}
	if(exchange == 1){
		D = L->vet[i];
		L->vet[i] = L->vet[menor];
		L->vet[menor] = D; 
}
}
}















int menu(){

	int escolha;

printf("\n\n>>>PROGRAMA DE CADASTRO DE NOMES<<<");


printf("\n(1) Inserir");
printf("\n(2) Deletar");
printf("\n(3) Mostrar");
printf("\n(4) Ordenar");
printf("\n(5) Sair");

printf("\ndigite o numero da sua opção: ");
scanf("%d", &escolha);

return escolha;
}




int main(){

	tipoLista L;


	int escolha;

iniciar_lista(&L);


    for ( ; ; )
    {
         escolha = menu();
         switch(escolha)
         {
             case 1: 
		inserir_lista(&L);
		break;
	     case 2:
		deletar_lista(&L);
		break;
	     case 3:
		mostrar_lista(&L);
		break;
	     case 4:
		ordenar_lista(&L);
		break;	
	     case 5:
		exit(0);
         }
    }






return 0;
}











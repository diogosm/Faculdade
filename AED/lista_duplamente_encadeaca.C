/************************************************************
  Diogo Soares Moreira
  20810205
  Algoritmos e estrutura de dados I 
  Lista Duplamente Encadeada
************************************************************/


#include<stdio.h>
#include<stdlib.h>


typedef struct{
	int num;
} tipoDados;

//declara o tipo da lista.
typedef struct no *p;
	
typedef struct no{
	tipoDados D;
	p ant;
	p prox;
} tipoNo;


typedef struct{
	p pri, ult;
} tipoLista;


tipoDados D2;
tipoLista lista;




//////////////////////////////////////////////////////////////




void criar_lista(tipoLista *L){
	L->pri = (p)malloc(sizeof(tipoNo));
	L->ult = L->pri;
	L->pri->prox = NULL;
	L->pri->ant = NULL;
}





void inserir_lista(tipoLista *L, tipoDados x){
	
	p aux;	
	
	L->ult->prox = (p)malloc(sizeof(tipoNo));
	aux = L->ult;
	L->ult = L->ult->prox;
	L->ult->D = x;
	L->ult->ant = aux; 
	L->ult->prox = NULL;
}



void inserir(){
	printf("\nInsira um numero: ");
	scanf("%d", &D2.num);

	inserir_lista(&lista, D2);
}



void mostrar_lista(tipoLista L){
	p aux;
	aux = L.pri->prox;


while(aux != NULL){
	printf("%d\n", aux->D.num);
	aux = aux->prox;
	}
}	







int estah_cheia(tipoLista L){
	return (L.pri == L.ult);
}

void remover_lista(tipoLista *L, tipoDados x){
	if(estah_cheia(*L)){
		printf("\nLista vazia!!!!!!!!\n");
		return;
	}

p aux, aux2;

aux = L->pri;
aux2 = L->pri->prox;

		while((aux2 != NULL) && (x.num != aux2->D.num)){
			aux = aux2;
			aux2 = aux2->prox;
		}

p aux3;

if(aux2->prox != NULL){
	aux3 = aux2->prox;
	aux->prox = aux2->prox;
	aux3->ant = aux;
	free(aux2);
	printf("\nElemento removido com sucesso!!!\n");
	}
		else if(aux2->D.num == x.num){
			L->ult = aux;
			aux->prox = NULL;
			free(aux2);
			printf("\nElemento removido com sucesso!!!\n");
			}
		else{
			printf("\nElemento inexistente!!!\n");
		}
}


void remover(){
	printf("\nInsira um elemento a ser excluido!!!\n");
	scanf("%d", &D2.num);
	
	remover_lista(&lista, D2);
}


void buscar_lista(tipoLista L, tipoDados x){
	if(estah_cheia(L)){
		printf("\nLista vazia!!!!!!!!\n");
		return;
	}

p aux;
aux = L.pri->prox;

while(aux!=NULL){
	if((aux->D.num == x.num)){
		printf("\nElemento existe na lista!!!!!\n");
		return;
	}
	aux = aux->prox;
}

	printf("\nElemento não existe na lista!!!!!!!\n");

}


void buscar(){
	printf("\nDigite o numero a ser buscado: ");
	scanf("%d", &D2.num);
	buscar_lista(lista, D2);
}


int menu(){
	int x;


printf("\n---------Programa de Lista Encadeada----------\n");
printf("-----------(1) Inserir na Lista-----------------\n");
printf("-----------(2) Deletar elemento da lista--------\n");
printf("-----------(3) Mostrar Lista--------------------\n");
printf("-----------(4) Buscar na lista------------------\n");
printf("-----------(5) Sair-----------------------------\n");

printf("\nDigite a sua opção: ");
scanf("%d", &x);

printf("\n\n");
return x;
}



//////////////////////////////////////////////////////////



int main(){


criar_lista(&lista);
	int escolha;

for(;;){
	escolha = menu();
	switch(escolha){
		case 1: 
			inserir();
			break;
		case 2:
			remover();
			break;
		case 3:
			mostrar_lista(lista);
			break;
		case 4:
			buscar();
			break;
		case 5: 
			exit(0);
	}
}			




















return 0;
}


	


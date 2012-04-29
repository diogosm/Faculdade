#include<stdio.h>
#include<stdlib.h>


struct bloco
{
int info;
struct bloco *prox;
struct bloco *ante;
};
typedef struct bloco Elemento;

struct lista
{
Elemento *inicio;
Elemento *fim;
};
typedef struct lista Lista;

Lista *criaLista()
{
Lista *lista;
      lista = (Lista*)malloc(sizeof(Lista));
            lista->inicio = NULL;
            lista->fim = NULL;
return lista;
}


void insereInicio(Lista *lista, int num)
{
Elemento *novo;
         novo = (Elemento*)malloc(sizeof(Elemento));
              novo->info = num;
              novo->prox = lista->inicio;
		novo->ante = lista->fim;
		if(lista->inicio == NULL)
		{
			lista->fim = novo;
		}
		lista->inicio = novo;
		lista->fim->prox = lista->inicio;
}


void imprimeLista(Lista *lista)
{
Elemento *caminha;
         caminha = lista->inicio;
         printf("(%d, ", caminha->info);
         while(caminha->prox != lista->inicio)
         {
                       printf("%d, ", caminha->prox->info);
                       caminha = caminha->prox;
         }
         printf(")");
} 


int main()
{
Lista *lista;
      lista = criaLista();
            insereInicio(lista, 5);
            insereInicio(lista, 4);
            insereInicio(lista, 3);
            insereInicio(lista, 2);
            insereInicio(lista, 1);
            insereInicio(lista, 0);
            printf("\n\n\n");
           imprimeLista(lista);
return 0;
}

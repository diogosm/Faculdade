#include <stdio.h>
#include <string.h>


struct dados
{
	char nome[50];
	int idade;
};

struct no_lista
{
	struct dados d;
	struct no_lista *prox;
};

struct lista
{
	struct no_lista *prim;
};


void Criar_Lista (struct lista *l)
{
	l->prim = NULL;
}

void Insere_Lista (struct lista *l)
{
	struct no_lista *novo;
	novo = (struct no_lista *) malloc (sizeof (struct no_lista));
	printf ("Nome: ");
	fgets (novo->d.nome,50,stdin);
	printf ("Idade: ");
	scanf ("%d",&novo->d.idade);
	getc (stdin);
	novo->prox = l->prim;
	l->prim = novo;
}

void Mostra_Lista (struct lista *l)
{
	struct no_lista *aux;
	if (l->prim==NULL)
	{
		printf ("A lista esta vazia\n\n");
	}
	else
	{
		for (aux = l->prim; aux!=NULL; aux = aux->prox)
		{
			printf ("%s\n",aux->d.nome);
			printf ("%d\n\n",aux->d.idade);
		}
	}
}

void Remove_Lista (struct lista *l)
{
	struct no_lista *aux, *ant;
	char nome[50];
	printf ("Digite o nome: ");
	fgets (nome,50,stdin);
	aux = l->prim;
	if (l->prim==NULL)
	{
		printf ("A lista esta vazia\n\n");
	}
	else if (!strcmp (aux->d.nome,nome))
	{
		l->prim = aux->prox;
		free (aux);
		printf ("Elemento removido com sucesso\n");
	}
	else
	{
		ant = l->prim;
		for (aux = aux->prox; aux!=NULL; aux = aux->prox)
		{
			if (!strcmp(aux->d.nome,nome))
			{
				ant->prox = aux->prox;
				free (aux);
				printf ("Elemento removido com sucesso\n");
			}
			ant = aux;
		}
	}
}

void Limpa_Lista (struct lista *l)
{
	struct no_lista  *aux;
	for (aux=l->prim; aux!=NULL; aux=l->prim)
	{
		l->prim = aux->prox;
		free (aux);
	}
}

void Ordena_Lista_Selecao (struct lista *l)
{	
	struct dados dados;
	struct no_lista *aux1, *aux2, *end;
	if (l->prim==NULL)
	{
		printf ("A lista esta vazia\n\n");
	}
	else
	{
		for (aux1 = l->prim; aux1->prox!=NULL; aux1 = aux1->prox)
		{
			dados = aux1->d;
			end = aux1;
			for (aux2=aux1->prox; aux2!=NULL; aux2=aux2->prox)
			{
				if (strcmp(aux2->d.nome,dados.nome)<0)
				{
					dados = aux2->d;
					end = aux2;
				}
			}
			end->d = aux1->d;
			aux1->d = dados;
		}
		printf ("Ordenacao realizada com sucesso\n");
	}
}

void Inverte_Lista (struct lista *l)
{
	struct no_lista *aux, *ant;
	if (l->prim==NULL)
	{
		printf ("A lista esta vazia\n\n");
	}
	else
	{
		aux = l->prim;
		ant = l->prim;	
		while (aux->prox!=NULL)
		{
			l->prim = aux->prox;
			aux->prox = aux->prox->prox;
			l->prim->prox = ant;
			ant = l->prim;
		}
		printf ("A lista foi invertida com sucesso\n\n");
	}
}

int main ()
{
	struct lista l;
	int x;
	system ("clear");
	Criar_Lista (&l);
	do
	{
		printf ("--------------------------------------------------------------------------------\n");
		printf ("\t\t\tLista Encadeada\n");
		printf ("[1]-Inserir\n");
		printf ("[2]-Mostrar\n");
		printf ("[3]-Remover\n");
		printf ("[4]-Ordenar (Selecao)\n");
		printf ("[5]-Inverter\n");
		printf ("[0]-Sair\n");
		printf ("--------------------------------------------------------------------------------\n");
		printf ("Escolha uma das opcoes acima: ");
		scanf ("%d",&x);
		getc (stdin);
		switch (x)
		{
			case 1:
				Insere_Lista (&l);
				break;
			case 2:
				Mostra_Lista (&l);
				break;
			case 3:
				Remove_Lista (&l);
				break;
			case 4:
				Ordena_Lista_Selecao (&l);
				break;
			case 5:
				Inverte_Lista (&l);
				break;
		} 
	}while (x!=0);
	Limpa_Lista (&l);
}



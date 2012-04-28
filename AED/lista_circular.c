#include <stdio.h>
#include <string.h>
//--------------------------------------------------------------------------------------------------------------------------

struct dados
{
	char nome[50];
	int idade;
};

struct no_lista_circular
{
	struct dados d;
	struct no_lista_circular *prox;
};

struct lista_circular
{
	struct no_lista_circular *atual;
};

//--------------------------------------------------------------------------------------------------------------------------
void Criar_Lista_Circular (struct lista_circular *lc)
{
	lc->atual = NULL;
}

void Insere_Lista_Circular (struct lista_circular *lc)
{
	struct no_lista_circular *novo;
	novo = (struct no_lista_circular *) malloc (sizeof (struct no_lista_circular));
	printf ("Nome: ");
	fgets (novo->d.nome,50,stdin);
	printf ("Idade: ");
	scanf ("%d",&novo->d.idade);
	getc (stdin);
	if (lc->atual==NULL)
	{
		novo->prox = novo;
		lc->atual = novo;
	}
	else
	{
		novo->prox = lc->atual->prox;
		lc->atual->prox = novo;
		lc->atual = novo;
	}
}

void Mostra_Lista_Circular (struct lista_circular *lc)
{
	struct no_lista_circular *aux;
	aux = lc->atual;
	do
	{
		printf ("Nome: %s\n",aux->d.nome);
		printf ("Idade: %d\n\n",aux->d.idade);
	}while (aux!=lc->atual);
}

/*void Remove_Lista_Circular (struct lista_circular *l)
{
	struct no_lista_circular *aux;
	aux = lc->atual;
	if (aux==NULL)
	{
		printf ("A lista esta vazia\n\n");
	}
	else if (aux==aux->prox)
	{
		lc->atual = NULL;
		free (aux);
	}
	else
	{
		
		while (aux->prox!=lc->atual)
		{
			aux = aux->prox;
		}
		aux->prox = lc->atual->prox;
		free (lc->atual);
		lc->atual = aux;
	}
}

void Limpa_Lista_Circular (struct lista_circular *lc)
{
	struct no_lista_circular  *aux, *temp;
	temp = lc->atual;
	aux = lc->atual;
	do
	{
		lc->atual = lc->atual->prox;
		free (aux);
		aux = lc->atual;
	}while (aux!=temp)
	
}*/


void Inverte_Lista_Circular (struct lista_circular *lc)
{
	struct no_lista_circular *aux, *ant;
	if (lc->atual=NULL)
	{
		printf ("A lista esta vazia\n\n");
	}
	else
	{
		ant = lc->atual
		do
		{
			aux = lc->atual->prox;
			lc->atual->prox = lc->atual->prox->prox;
			aux->prox = ant;
			ant = aux;
		}while (aux!=lc->atual)
	}
	
}
//------------------------------------------------------------------------------------------------------------------------
int main ()
{
	struct lista_circular *lc; 
	int x;
	system ("CLR");
	Criar_Lista_Circular (&lc);
	do
	{
		printf ("--------------------------------------------------------------------------------\n");
		printf ("\t\t\tLista Circular\n");
		printf ("[1]-Inserir\n");
		printf ("[2]-Mostrar\n");
		printf ("[3]-Remover\n");
		printf ("[4]-Inverter\n");
		printf ("[0]-Sair\n");
		printf ("--------------------------------------------------------------------------------\n");
		printf ("Escolha uma das opcoes acima: ");
		scanf ("%d",&x);
		getc (stdin);
		switch (x)
		{
			case 1:
				Insere_Lista_Circular (&lc);
				break;
			case 2:
				Mostra_Lista_Circular (&lc);
				break;
			case 3:
				Remove_Lista_Circular (&lc);
				break;
			case 4:
				Inverte_Lista_Circular (&lc);
				break;
		} 
	}while (x!=0);
	Limpa_Lista_Circular (&lc);
}
//-----------------------------------------------------------------------------------------------------------------------

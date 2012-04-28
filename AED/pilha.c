#include <stdio.h>
#include <string.h>
//--------------------------------------------------------------------------------------------------------------------------
struct dados
{
	char nome[50];
	int idade;
};

struct no_pilha
{
	struct dados d;
	struct no_pilha *prox;
};

struct pilha
{
	struct no_pilha *topo;
};
//--------------------------------------------------------------------------------------------------------------------------
void Criar_Pilha (struct pilha *p)
{
	p->topo = NULL;
}

void Insere_Pilha (struct pilha *p)
{
	struct no_pilha *novo;
	novo = (struct no_pilha *) malloc (sizeof(struct no_pilha));
	printf ("Nome: ");
	fgets (novo->d.nome,50,stdin);
	printf ("Idade: ");
	scanf ("%d",&novo->d.idade);
	getc (stdin);
	novo->prox = p->topo;
	p->topo = novo;
}

void Mostra_Pilha (struct pilha *p)
{
	struct no_pilha *aux;
	if (p->topo==NULL)
	{
		printf ("A pilha esta vazia\n\n");
	}
	else
	{
		for (aux=p->topo;aux!=NULL;aux=aux->prox)
		{
			printf ("%s\n",aux->d.nome);
			printf ("%d\n\n",aux->d.idade);
		}
	}
}

void Remove_Pilha (struct pilha *p)
{
	struct no_pilha *aux;
	if (p->topo==NULL)
	{
		printf ("A pilha esta vazia\n");
	}
	else
	{
		aux = p->topo;
		p->topo = aux->prox;
		free (aux);
		printf ("Elemento removido com sucesso\n\n");
	}
}

void Limpa_Pilha (struct pilha *p)
{
	struct no_pilha *aux;
	for (aux=p->topo;aux!=NULL;aux=p->topo)
	{
		p->topo = aux->prox;
		free (aux);
	}
}
//------------------------------------------------------------------------------------------------------------------------
int main ()
{
	struct pilha p;
	int x;
	system ("clear");
	Criar_Pilha (&p);
	do
	{
		printf ("--------------------------------------------------------------------------------\n");
		printf ("\t\t\t\tPilha\n");
		printf ("[1]-Inserir\n");
		printf ("[2]-Mostrar\n");
		printf ("[3]-Remover\n");
		printf ("[0]-Sair\n");
		printf ("--------------------------------------------------------------------------------\n");
		printf ("Escolha uma das opcoes acima: ");
		scanf ("%d",&x);
		getc (stdin);
		switch (x)
		{
			case 1:
				Insere_Pilha (&p);
				break;
			case 2:
				Mostra_Pilha (&p);
				break;
			case 3:
				Remove_Pilha (&p);
				break;
		} 
	}while (x!=0);
	Limpa_Pilha (&p);
}


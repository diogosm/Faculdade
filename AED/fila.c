#include <stdio.h>
#include <string.h>
/*--------------------------------------------------------------------------------------------------------------------------*/
struct dados
{
	char nome[50];
	int matricula;
};

struct no_fila
{
	struct dados d;
	struct no_fila *prox;
};

struct fila
{
	struct no_fila *prim, *ult;
};
void Criar_Fila (struct fila *f)
{
	f->prim = NULL;
	f->ult = NULL;
}

void Insere_Fila (struct fila *f)
{
	struct no_fila *novo;
	novo = (struct no_fila *) malloc (sizeof (struct no_fila));
	novo->prox = NULL;
	printf ("Nome: ");
	fgets (novo->d.nome,50,stdin);
	printf ("Matricula: ");
	scanf ("%d",&novo->d.matricula);
	if (f->prim==NULL)
	{
		f->prim = novo;
		f->ult = novo;
	}
	else
	{
		f->ult->prox = novo;
		f->ult = novo;
	}
	printf ("Aluno cadastrado com sucesso!\n");
}

void Mostra_Fila (struct fila *f)
{
	struct no_fila *aux;
	if (f->prim==NULL)
	{
		printf ("A fila esta vazia\n\n");
	}
	else
	{
		for (aux=f->prim; aux!=NULL; aux=aux->prox)
		{
			printf ("%s\n",aux->d.nome);
			printf ("%d\n\n",aux->d.matricula);
		}
	}
}

void Remove_Fila (struct fila *f)
{
	struct no_fila *aux;
	aux = f->prim;
	if (aux==NULL)
	{
		printf ("A fila esta vazia\n\n");
	}
	else
	{
		f->prim = aux->prox;
		free (aux);
	}
	printf ("Aluno Removido!\n\n");
}

int main ()
{
	struct fila f;
	int x;
	system ("CLS");
	Criar_Fila (&f);
	do
	{
		printf ("--------------------------------------------------------------------------------\n");
		printf ("\t\t\t\tFila\n");
		printf ("[1]-Cadastrar\n");
		printf ("[2]-Consultar\n");
		printf ("[3]-Remover\n");
		printf ("[0]-Sair\n");
		printf ("--------------------------------------------------------------------------------\n");
		printf ("Escolha uma das opcoes acima: ");
		scanf ("%d",&x);
		getc (stdin);
		switch (x)
		{
			case 1:
				Insere_Fila (&f);
				break;
			case 2:
				Mostra_Fila (&f);
				break;
			case 3:
				Remove_Fila (&f);
				break;
		} 
	}while (x!=0);
//	Limpa_Fila (&f);
}

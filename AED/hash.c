#include<stdio.h>
#define N 7

typedef struct aluno
{	
	char nome[30];
	int matricula;
	struct aluno *prox;
}TAluno;

TAluno *hash[N];

void inicializa(Hash tab)
{
	int i;

	for(i=0;i<N;i++)
		tab[i] = NULL;
}

int hash(int matricula)
{	
	return (matricula % N);	
}

void insere(Hash tab, int matricula, char nome)
{
	int h = hash(matricula);

	TAluno *novo = (TAluno*) malloc(sizeof(TAluno));
	novo->matricula = matricula;
	strcpy(novo->nome,nome);
	
	if(tab[h] == NULL)
	{
		tab[h] = novo;
		novo->prox = NULL;
	}else{
		novo->prox = tab[h];
		tab[h] = novo;
	}
)

TAluno *busca(Hash tab, int matricula)
{
	TAluno *aux = tab[hash(matricula)];

	while(aux != NULL)
	{	
		if(aux->matricula == matricula)		
			return aux;

		aux = aux->prox;
	}
	
}

void imprime(Hash tab)
{
	int i;
	TAluno *aux;
	
	for(i = 0; i < N; i++)
	{
		aux = tab[i];
		while(aux != NULL)
		{
			printf("Matricula: %d Nome: %s\n",aux->matricula,aux->nome);
			aux = aux->prox;
		}
	}
}


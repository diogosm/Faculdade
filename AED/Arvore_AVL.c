#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//------------------------------------------------------------------------------
typedef struct avl
{
	int bal;	// guarda o balanco 
	int *val;
	struct avl *esq, *dir;
}Avl;
//------------------------------------------------------------------------------
Avl * Inicializa ()
{
	return NULL;
}
//------------------------------------------------------------------------------
int Arvore_Vazia (Avl *raiz)
{
	return (raiz == NULL);
}
//------------------------------------------------------------------------------
void Rotacao_Simples_Esquerda1 (Avl **a, Avl *b)
{
	(*a)->dir = b->esq;
	b->esq = (*a);
	(*a)->bal = 0;
	(*a) = b;
	(*a)->bal = 0;
}
//------------------------------------------------------------------------------
void Rotacao_Simples_Direita1 (Avl **a, Avl *b)
{
	(*a)->esq = b->dir;
	b->dir = (*a);
	(*a)->bal = 0;
	(*a) = b;
	(*a)->bal = 0;
}
//------------------------------------------------------------------------------
int Rotacao_Simples_Esquerda2 (Avl **a, Avl *b)
{	/* Este caso so ocorre na Remocao, quando b->bal = 0 */
	(*a)->dir = b->esq;
	b->esq = (*a);
	(*a)->bal = 1;
	b->bal = -1;
	(*a) = b;
	return 0;
}
//------------------------------------------------------------------------------
int Rotacao_Simples_Direita2 (Avl **a, Avl *b)
{	/* Este caso so ocorre na Remocao, quando b->bal = 0 */
	(*a)->esq = b->dir;
	b->dir = (*a);
	(*a)->bal = -1;
	b->bal = 1;
	(*a) = b;
	return 0;
}
//------------------------------------------------------------------------------
void Rotacao_Dupla_Esquerda (Avl **a, Avl *b, Avl *aux)
{
	b->dir = aux->esq;
	aux->esq = b;
	(*a)->esq = aux->dir;
	aux->dir = (*a);
	if (aux->bal == -1) (*a)->bal = 1;
	else (*a)->bal = 0;
	if (aux->bal == 1) b->bal = -1;
	else b->bal = 0;
	(*a) = aux;
	(*a)->bal = 0;
}
//------------------------------------------------------------------------------
void Rotacao_Dupla_Direita (Avl **a, Avl *b, Avl *aux)
{
	b->esq = aux->dir;
	aux->dir = b;
	(*a)->dir = aux->esq;
	aux->esq = (*a);
	if (aux->bal == 1) (*a)->bal = -1;
	else (*a)->bal = 0;
	if (aux->bal == -1) b->bal = 1;
	else b->bal = 0;
	(*a) = aux;
	(*a)->bal = 0;
}
//------------------------------------------------------------------------------
void Rotacao1 (Avl **a)
{
	Avl *b;
	b = (*a)->dir;
	if (b->bal == 1) Rotacao_Simples_Esquerda1 (a,b);
	else Rotacao_Dupla_Direita (a,b,b->esq);
}
//------------------------------------------------------------------------------
void Rotacao2 (Avl **a)
{
	Avl *b;
	b = (*a)->esq;
	if (b->bal == -1) Rotacao_Simples_Direita1 (a,b);
	else Rotacao_Dupla_Esquerda (a,b,b->dir);
}

//------------------------------------------------------------------------------

int Rotacao3 (Avl **a)
{
	Avl *b;
	b = (*a)->dir;
	if (b->bal == 0) return (Rotacao_Simples_Esquerda2 (a,b));
	else if (b->bal > 0) Rotacao_Simples_Esquerda1 (a,b);
	else Rotacao_Dupla_Direita (a,b,b->esq);
	return 1;
}

//------------------------------------------------------------------------------

int Rotacao4 (Avl **a)
{
	Avl *b;
	b = (*a)->esq;
	if (b->bal == 0) return (Rotacao_Simples_Direita2 (a,b));
	else if (b->bal < 0) Rotacao_Simples_Direita1 (a,b);
	else Rotacao_Dupla_Esquerda (a,b,b->dir);
	return 1;
}

//------------------------------------------------------------------------------

int Insere_Arvore_Avl (Avl **raiz, int *valor)
{
	if (Arvore_Vazia (*raiz))
	{
		(*raiz) = (Avl *) malloc (sizeof (Avl));
		(*raiz)->val = valor;
		(*raiz)->esq = NULL;
		(*raiz)->dir = NULL;
		(*raiz)->bal = 0;
		return 1;
	}
      else if ( valor > (*raiz)->val){
	  if (Insere_Arvore_Avl (&(*raiz)->dir,valor))
		{
			(*raiz)->bal++;
			if ((*raiz)->bal == 1) return 1;
			if ((*raiz)->bal == 2) Rotacao1 (raiz);
		}
	}
	else
	{
		if (Insere_Arvore_Avl (&(*raiz)->esq,valor))
		{
			(*raiz)->bal--;
			if ((*raiz)->bal == -1) return 1;
			if ((*raiz)->bal == -2) Rotacao2 (raiz);
		}
	}
	return 0;
}

//------------------------------------------------------------------------------

int * Maior_Esquerda (Avl *raiz)
{
	if (!Arvore_Vazia (raiz->dir)) return (Maior_Esquerda (raiz->dir));
	return (raiz->val);
}

//------------------------------------------------------------------------------

int * Menor_Direita (Avl *raiz)
{
	if (!Arvore_Vazia (raiz->esq)) return (Menor_Direita (raiz->esq));
	return (raiz->val);
}

//------------------------------------------------------------------------------
int Remove_Arvore_Avl (Avl **raiz, int *valor)
{
	if (!Arvore_Vazia (*raiz))
	{
		if ((*raiz)->val == valor)
		{
			if (!Arvore_Vazia ((*raiz)->esq))
			{
			(*raiz)->val = Maior_Esquerda ((*raiz)->esq);
				
				
	if (Remove_Arvore_Avl (&(*raiz)->esq,(*raiz)->val))
				{
					(*raiz)->bal++;
					if ((*raiz)->bal == 0) return 1;
					if ((*raiz)->bal == 1) return 0;
					if ((*raiz)->bal == 2) return (Rotacao3 (raiz));
				}
			}
	else if (!Arvore_Vazia ((*raiz)->dir))
			{
				(*raiz)->val = Menor_Direita ((*raiz)->dir);
	if (Remove_Arvore_Avl (&(*raiz)->dir,(*raiz)->val))
				{
					(*raiz)->bal--;
					if ((*raiz)->bal == 0) return 1;
					if ((*raiz)->bal == -1) return 0;
					if ((*raiz)->bal == -2) return (Rotacao4 (raiz));
				}
			}
		free ((*raiz)->val);
		free (*raiz);
		(*raiz) = NULL;
		return 1;
		}
	else if (valor >(*raiz)->val)
		{
			if (Remove_Arvore_Avl (&(*raiz)->dir,valor))
			{
				(*raiz)->bal--;
				if ((*raiz)->bal == 0) return 1;
				if ((*raiz)->bal == -2) return (Rotacao4 (raiz));
			}
		} 
		else
		{
			if (Remove_Arvore_Avl (&(*raiz)->esq,valor))
			{
				(*raiz)->bal++;
				if ((*raiz)->bal == 0) return 1;
				if ((*raiz)->bal == 2) return (Rotacao3 (raiz));
			}
		}
	}
	return 0;
}

//------------------------------------------------------------------------------

int Busca_Arvore_Avl (Avl *raiz, int *valor)
{
	if (Arvore_Vazia (raiz)) return 0;
	else if ( valor ==(raiz->val)) return 1;
	else if (valor < (raiz->val)) return (Busca_Arvore_Avl (raiz->esq,valor));
	else return (Busca_Arvore_Avl (raiz->dir,valor));
}

//------------------------------------------------------------------------------

Avl * Destroi_Arvore_Avl (Avl *raiz)
{
	if (!Arvore_Vazia (raiz))
	{
		if (!Arvore_Vazia (raiz->esq)) raiz->esq = Destroi_Arvore_Avl (raiz->esq);
		if (!Arvore_Vazia (raiz->dir)) raiz->dir = Destroi_Arvore_Avl (raiz->dir);
		free (raiz->val);
		free (raiz);
	} 
	return NULL;
}

//------------------------------------------------------------------------------

void Caminhamento_Pre_Ordem (Avl *raiz)
{
	if (!Arvore_Vazia (raiz))
	{
		printf ("%d\n",raiz->val);
		if (!Arvore_Vazia (raiz->esq)) Caminhamento_Pre_Ordem (raiz->esq);
		if (!Arvore_Vazia (raiz->dir)) Caminhamento_Pre_Ordem (raiz->dir);
	}
}

//------------------------------------------------------------------------------

void Caminhamento_Em_Ordem (Avl *raiz)
{
	if (!Arvore_Vazia (raiz))
	{
		if (!Arvore_Vazia (raiz->esq)) Caminhamento_Em_Ordem (raiz->esq);
		printf ("%d\n",raiz->val);
		if (!Arvore_Vazia (raiz->dir)) Caminhamento_Em_Ordem (raiz->dir);
	}
}

//------------------------------------------------------------------------------

void Caminhamento_Pos_Ordem (Avl *raiz)
{
	if (!Arvore_Vazia (raiz))
	{
		if (!Arvore_Vazia (raiz->esq)) Caminhamento_Pos_Ordem (raiz->esq);
		if (!Arvore_Vazia (raiz->dir)) Caminhamento_Pos_Ordem (raiz->dir);
		printf ("%d\n",raiz->val);
	}
}

//------------------------------------------------------------------------------

void Mostra_Arvore_Avl (Avl *raiz, int cont)
{
	int	x;
	for (x=cont; x>0; x--) printf ("  ");
	printf ("> ");
	if (!Arvore_Vazia (raiz))
	{
		printf ("%d (%d)\n",raiz->val,raiz->bal);
		Mostra_Arvore_Avl (raiz->esq,cont+1);
		Mostra_Arvore_Avl (raiz->dir,cont+1);
	}
	else printf ("-null-\n");
}

//------------------------------------------------------------------------------
int Altura_Arvore_Avl (Avl *raiz)
{
	if (Arvore_Vazia (raiz)) return -1;
	else if (raiz->bal == 1) return (Altura_Arvore_Avl (raiz->dir) + 1);
	else return (Altura_Arvore_Avl (raiz->esq) + 1);
}



//------------------------------------------------------------------------------
//programa final

    int main ()
{
	int x,y,z,n;
	Avl *raiz;
	int valor;
	raiz = Inicializa();
	system ("clear");
	do


	{
		printf ("================================================================================\n");
		printf ("\t\t\tArvore AVL\n\n");
			printf ("       O       [1] - Inserir Novo Elemento\n");
		printf ("      / \\      [2] - Mostrar a Estrutura da Arvore\n");
		printf ("     O   O     [3] - Buscar um Elemento\n");
		printf ("    / \\   \\    [4] - Remover um Elemento\n");
		printf ("   O   O   O   [5] - Destruir a Arvore\n");
		printf ("               [6] - Caminhar na Arvore\n");
		printf ("               [7] - Altura da Arvore\n");
		printf ("               [8] - Verificar se a arvore esta vazia\n");
		printf ("               [0] - Finalizar programa\n");
		
	
		printf ("================================================================================\n");
		printf ("Escolha uma das opcoes acima: ");
		scanf ("%d",&n);
		getc (stdin);
		printf ("================================================================================\n");
		switch (n)
		{
				case 1:
				printf (" Inserir: ");
				scanf ("%d",&x);
				Insere_Arvore_Avl (&raiz,x);
				break;
			case 2:
				Mostra_Arvore_Avl (raiz,0);
				break;
	       	case 3:
				printf ("buscar:");
				scanf ("%d",&x);
				y = Busca_Arvore_Avl (raiz,x);
				if (y) printf (" encontrado\n");
				else printf ("nao encontrado\n");
				break;
			
			case 4:
                 printf ("Elemento a ser removido: ");
				scanf ("%d",&y);
				Remove_Arvore_Avl (&raiz,y);
				break;
		   	case 5:
				raiz = Destroi_Arvore_Avl (raiz);
				printf ("Todos os elementos foram removidos\n");
				break;
			case 6:
				do
				{
					printf ("================================================================================\n");
					printf ("[1]-Pre-Ordem\n");
					printf ("[2]-Em-Ordem\n");
					printf ("[3]-Pos-Ordem\n");
					printf ("================================================================================\n");
					printf ("Escolha uma das opcoes acima: ");
					scanf ("%d",&x);
					getc (stdin);
					if (x==1) Caminhamento_Pre_Ordem (raiz);
					if (x==2) Caminhamento_Em_Ordem (raiz);
					if (x==3) Caminhamento_Pos_Ordem (raiz);
				} while (x<1 && x>3);
				printf ("\n");
				break;
			case 7:
				x = Altura_Arvore_Avl (raiz);
				printf ("Altura da Arvore: %d\n",x);
				break;
			case 8:
				x = Arvore_Vazia  (raiz);
				if (x) printf ("A arvore esta vazia\n");
				else printf ("A arvore nao esta vazia\n");
	 }
	}while (n!=0);
	raiz = Destroi_Arvore_Avl (raiz);
	printf ("\n");
}

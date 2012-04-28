#include <stdio.h>
#include <stdlib.h>

// Estrutura da arvore

typedef struct arvore
{
	int val;
	struct arvore *esq, *dir;
}Arvore;

//-------------------------------------------------------------------------------------------------------------

Arvore * Inicializa_Arvore_Binaria ()
{
	return NULL;
}

//---------------------------------------------------------------------------------------------------------------
void Insere_Arvore_Binaria (Arvore **raiz, int valor)
{
	if ((*raiz) == NULL)
	{
		(*raiz) = (Arvore *) malloc (sizeof (Arvore));
		(*raiz)->val = valor;
		(*raiz)->esq = NULL;
		(*raiz)->dir = NULL;
	}
//	if ((*raiz)->val == valor){        ATENÇÂO VERIFICAR CONDIÇÂO
 //    printf(" 1");
     
	else if (valor > (*raiz)->val) Insere_Arvore_Binaria (&((*raiz)->dir),valor);
	else Insere_Arvore_Binaria (&((*raiz)->esq),valor);
        
}

//-------------------------------------------------------------------------------------------------------------
void Caminhamento_Infixado (Arvore *raiz)
{
	if (raiz != NULL)
	{
		Caminhamento_Infixado (raiz->esq);
		printf ("%d ",raiz->val);
		Caminhamento_Infixado (raiz->dir);
	}
}

//-------------------------------------------------------------------------------------------------------------
void Caminhamento_Pre_Fixado (Arvore *raiz)
{
	if (raiz != NULL)
	{
		printf ("%d ",raiz->val);
		Caminhamento_Pre_Fixado (raiz->esq);
		Caminhamento_Pre_Fixado (raiz->dir);
	}
}

//-------------------------------------------------------------------------------------------------------------
void Caminhamento_Pos_Fixado (Arvore *raiz)
{
	if (raiz != NULL)
	{
		Caminhamento_Pos_Fixado (raiz->esq);
		Caminhamento_Pos_Fixado (raiz->dir);
		printf ("%d ",raiz->val);
	}
}

//------------------------------------------------------------------------------------------------------------
int Busca_Arvore_Binaria (Arvore *raiz, int valor)
{
	if (!raiz) return 0;
	else if (raiz->val == valor) return 1;
	else if (valor > raiz->val) return (Busca_Arvore_Binaria (raiz->dir,valor));
	else return (Busca_Arvore_Binaria (raiz->esq,valor));
}

//------------------------------------------------------------------------------------------------------------
void Libera_Memoria (Arvore **raiz)
{
	if ((*raiz) != NULL)
	{
		if ((*raiz)->esq) Libera_Memoria (&(*raiz)->esq);
		if ((*raiz)->dir) Libera_Memoria (&(*raiz)->dir);
		free (*raiz);
		*raiz = NULL;
	}
}

//------------------------------------------------------------------------------------------------------------
Arvore ** Maior_Esquerda (Arvore **raiz)
{
	if ((*raiz)->dir != NULL) return (Maior_Esquerda (&((*raiz)->dir)));
	return raiz;
}

//-----------------------------------------------------------------------------------------------------------
Arvore ** Menor_Direita (Arvore **raiz)
{
	if ((*raiz)->esq != NULL) return (Menor_Direita (&(*raiz)->esq));
	return raiz;
}

//----------------------------------------------------------------------------------------------------------
void Remove_Arvore_Binaria (Arvore **raiz, int valor)
{
	Arvore **aux, *tmp;
	if ((*raiz) == NULL){
        printf ("Nao e possivel fazer a remocao\n");
        }
	else if ((*raiz)->val == valor)
	{
		aux = raiz;
		tmp = NULL;
		if ((*raiz)->esq != NULL)
		{
			aux = Maior_Esquerda (&(*raiz)->esq);
			tmp = (*aux)->esq;
		}
		else if ((*raiz)->dir != NULL)
		{
			aux = Menor_Direita (&(*raiz)->dir);
			tmp = (*aux)->dir;
		}
		(*raiz)->val = (*aux)->val;
		free (*aux);
		(*aux) = tmp;system ("clear");
	}
	else if (valor > (*raiz)->val) Remove_Arvore_Binaria (&((*raiz)->dir),valor);
	else Remove_Arvore_Binaria (&((*raiz)->esq),valor);
}

//-----------------------------------------------------------------------------------------------------------
void Altera_Arvore_Binaria (Arvore **raiz, int x, int y)
{
	Remove_Arvore_Binaria (raiz,x);
	Insere_Arvore_Binaria (raiz,y);
	printf ("Elemento modificado\n");
}

//---------------------------------------------------------------------------------------------------------
int Altura_Arvore (Arvore *raiz)
{
	int x,y;
	if (raiz == NULL) return -1;
	x = Altura_Arvore (raiz->esq)+1;
	y = Altura_Arvore (raiz->dir)+1;
	return ((x>y) ? x : y);
}
//-------------------------------------------------------------------------------------------------------------


int main ()
{
	int x,y,z,n;
	Arvore *raiz;
	raiz = Inicializa_Arvore_Binaria ();
	system ("clear");
	do
	{
         printf ("\t\t\tArvore Binaria\n\n");
			printf ("       O       [1] - Inserir \n");
		printf ("      / \\      [2] - Mostrar \n");
		printf ("     O   O     [3] - Buscar \n");
		printf ("    / \\   \\    [4] - Modificar\n");
		printf ("   O   O   O   [5] - Remover\n");
		printf ("               [6] - Remover todos \n");
		printf ("               [7] - Altura\n");
	
		printf ("               [0] - Finalizar programa\n");
		
	
		printf ("================================================================================\n");
		printf ("Escolha uma das opcoes acima: ");
		scanf ("%d",&n);
		printf ("================================================================================\n");
		switch (n)
		{
			case 1:
				printf ("Elemento a ser inserido: ");
				scanf ("%d",&x);
				Insere_Arvore_Binaria (&raiz,x);
				printf ("Elemento inserido com sucesso\n");
				break;
			case 2:
				do
				{
					printf ("================================================================================\n");
					printf ("[1]-Pre-Fixado\n");
					printf ("[2]-Infixado\n");
					printf ("[3]-Pos-Fixado\n");
					printf ("================================================================================\n");
					printf ("Escolha uma das opcoes acima: ");
					scanf ("%d",&x);
                    if (x==1) Caminhamento_Pre_Fixado (raiz);
					if (x==2) Caminhamento_Infixado (raiz);
					if (x==3) Caminhamento_Pos_Fixado (raiz);
				} while (x<1 && x>3);
				printf ("\n");
				break;
			case 3:
				printf ("Elemento a ser buscado: ");
				scanf ("%d",&x);
				y = Busca_Arvore_Binaria (raiz,x);
				if (y) printf ("Elemento encontrado\n");
				else printf ("Elemento nao encontrado\n");
				break;
			case 4:
				printf ("Elemento a ser modificado: ");
				scanf ("%d",&y);
				printf ("O elemento %d sera modificado por: ",y);
				scanf ("%d",&z);
				Altera_Arvore_Binaria (&raiz,y,z);
				break;
			case 5:
				printf ("Elemento a ser removido: ");
				scanf ("%d",&y);
				Remove_Arvore_Binaria (&raiz,y);
				break;
			case 6:
				Libera_Memoria (&raiz);
				printf ("Todos os elementos foram removidos com sucesso\n");
				break;
			case 7:
				x = Altura_Arvore (raiz);
				printf ("Altura da Arvore: %d\n",x);
				break;
		} 
	}while (n!=0);
	Libera_Memoria (&raiz);
	printf ("\n");
}

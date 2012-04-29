#include<stdio.h>
#include<stdlib.h>



typedef struct no{
	struct no *esq;
	struct no *dir;
	int valor;
} arvore;


void criar(arvore **K, FILE *fp){
	fprintf(fp, "# Cria uma nova arvore\n");
	fprintf(fp, "Arvore criada\n\n");
	*K = NULL;
}	


void inserir(arvore **K, int valor, FILE *fp){
	
	while(*K!=NULL){
		if(valor > (*K)->valor){
			K = &((*K)->dir);
		}
		else{
			if(valor < (*K)->valor){
				K = &((*K)->esq);
			}
			else{
				fprintf(fp, "elemento %d não inserido\n", valor);				
				return;
			}
		}
	}
	
	*K=(arvore *)malloc(sizeof(arvore));
	(*K)->valor = valor;
	(*K)->esq = NULL;
	(*K)->dir = NULL;
	fprintf(fp, "elemento %d inserido\n", valor);
	return;	
}


int pesquisa(arvore *K, int valor, FILE *fp){
	if(K==NULL){
		fprintf(fp, "# Pesquisa pelo item %d\n", valor);
		fprintf(fp, "Item %d não existente\n\n", valor);
		return 0;
	}
	if(valor>K->valor){
		return pesquisa(K->dir, valor, fp);
	}
	else{
		if(valor<K->valor){
			return pesquisa(K->esq, valor, fp);
		}
		else{
			fprintf(fp, "# Pesquisa pelo item %d \n", valor);
			fprintf(fp, "Item %d achado\n\n", valor);
			return 1;
		}
	}
}


void remocao(arvore **K, int valor, FILE *fp){
	if((*K)==NULL){
		fprintf(fp, "\nItem %d não removido\n\n", valor);
		return;
	}
	
while(*K != NULL){
	if(valor>(*K)->valor){
		K = &((*K)->dir);
	}
	else{
		if(valor<(*K)->valor){
			K = &((*K)->esq);
		}
		else{
			arvore *aux;
			if((*K)->esq==NULL){
				aux = *K;
				*K = (*K)->dir;
				free(aux);
				fprintf(fp, "Item %d removido\n", valor);
				return;
			}
			else{
				if((*K)->dir == NULL){
					aux = *K;
					*K = (*K)->esq;
					free(aux);
					fprintf(fp, "Item %d removido\n", valor);
					return;
				}
				else{
					aux = *K;
					arvore *aux2;
					aux2 = (*K)->esq;
					(*K) = (*K)->dir;
					while((*K)->esq!=NULL){
						K = &((*K)->esq);
					}
					(*K)->esq = aux2;
					free(aux);
					fprintf(fp, "Item %d removido\n", valor);
					return;
				}
			}
		}
	}
}
}



void pre_ordem(arvore *K, FILE *fp){
	if(!K){
		return;
	}
	fprintf(fp, "-%d \n", K->valor);
	pre_ordem(K->esq, fp);
	pre_ordem(K->dir, fp);
}


void central(arvore *K, FILE *fp){
	if(!K){
		return;
	}
	central(K->esq, fp);
	fprintf(fp, "-%d \n", K->valor);
	central(K->dir, fp);
}


void pos_ordem(arvore *K, FILE *fp){
	if(!K){
		return;
	}
	pos_ordem(K->esq, fp);
	pos_ordem(K->dir, fp);
	fprintf(fp,"-%d \n ", K->valor);
}


int menor_arvore(arvore *K, FILE *fp){
	if(K==NULL){
		return -1;
	}
	while(K->esq != NULL){
		K=K->esq;
	}
	fprintf(fp, "O menor item eh %d\n", K->valor);
	return K->valor;
}

int maior_arvore(arvore *K, FILE *fp){
	if(K==NULL){
		return -1;
	}
	while(K->dir != NULL){
		K = K->dir;
	}
	fprintf(fp, "O maior item eh %d\n", K->valor);
	return K->valor;
}


int soma_elem(arvore *K){
	if(K==NULL){
		return 0;
	}
	return K->valor+soma_elem(K->esq)+soma_elem(K->dir);
}

void soma(arvore *K, FILE *fp){
	int x = soma_elem(K);
	fprintf(fp, "\n# Retorna a soma dos elementos \n");
	fprintf(fp, "A soma dos elementos eh: %d\n\n", x);
	return;
}

int sub_arvore_maior(arvore *K, int x){
	if(K==NULL){
		return -1;
	}
	while(K!=NULL){
		if(x>K->valor){
			K = K->dir;
		}
		else{
			if(x<K->valor){
				K = K->esq;
			}
			else{
				int dir, esq;
				dir = soma_elem(K->dir);
				esq = soma_elem(K->esq);
				
				if(dir<esq){
					return 1;
				}
				else{
					if(dir>esq){
						return 2;
					}	
					else{
						return -1;
					}
				}
			}
		}
	}
}


void sub_arvore_maior2(arvore *K, int x, FILE *fp){
	int y = sub_arvore_maior(K, x);
	fprintf(fp, "\n# Retorna a maior sub-arvore\nA sub arvore maior eh(-1-nenhuma) (1-esquerda) (2-direira): %d\n\n", y);
	
}
	

int altura(arvore *K){
	if(K==NULL){
		return 0;
	}
	else{
		int esq, dir;
		esq = altura(K->esq);
		dir = altura(K->dir);
		if(esq>dir){
			return esq+1;
		}
		else{
			return dir+1;
		}
	}
}

void altura2(arvore *K, FILE *fp){
	int x = altura(K);
	fprintf(fp, "A altura eh: %d\n\n", x);
}


void inserir2(arvore **K, int valor){
	
	while(*K!=NULL){
		if(valor > (*K)->valor){
			K = &((*K)->dir);
		}
		else{
			if(valor < (*K)->valor){
				K = &((*K)->esq);
			}
			else{
				return;
			}
		}
	}
	
	*K=(arvore *)malloc(sizeof(arvore));
	(*K)->valor = valor;
	(*K)->esq = NULL;
	(*K)->dir = NULL;	
}


void remocao2(arvore **K, int valor){
	if((*K)==NULL){
		return;
	}
	
while(*K != NULL){
	if(valor>(*K)->valor){
		K = &((*K)->dir);
	}
	else{
		if(valor<(*K)->valor){
			K = &((*K)->esq);
		}
		else{
			arvore *aux;
			if((*K)->esq==NULL){
				aux = *K;
				*K = (*K)->dir;
				free(aux);
				return;
			}
			else{
				if((*K)->dir == NULL){
					aux = *K;
					*K = (*K)->esq;
					free(aux);
					return;
				}
				else{
					aux = *K;
					arvore *aux2;
					aux2 = (*K)->esq;
					(*K) = (*K)->dir;
					while((*K)->esq!=NULL){
						K = &((*K)->esq);
					}
					(*K)->esq = aux2;
					free(aux);
				}
			}
		}
	}
}
}



void modifica_noh(arvore **K, int antigo, int novo, FILE *fp){
	if(*K==NULL){
		return;
	}
	fprintf(fp, "Item %d alterado para %d \n\n", antigo, novo);		
	remocao2(K, antigo);
	inserir2(K, novo);
	
}
	




int main(void){
	arvore *K;
	int num1, num2;
	char line[1001];
	char vet[10];
	FILE *in;
	in = fopen("in.txt", "rt");
	FILE *out;
	out = fopen("out.txt", "wt");

	
	while(fgets(line, 1000, in)!=NULL){
		sscanf(line, "%s %d %d", vet, &num1, &num2);
		switch(vet[0]){
			case '#': 
				break;
			case 'c': 
				criar(&K, out); 
				break;
			case 'i':
				inserir(&K, num1, out);
				break;
			case 'r': 
			 	remocao(&K, num1, out);	
				break;
			case 'a':
				fprintf(out, "\n# Alterar um elemento da arvore\n");
				modifica_noh(&K, num1, num2, out);										
				break;
			case 'p':
				pesquisa(K,num1, out);
				break;
			case 'M':
				fprintf(out, "# Retorna o maior valor\n");
				maior_arvore(K, out);
				break;
			case 'm':
				fprintf(out, "\n# retorna o menor da arvore\n");
				menor_arvore(K, out);
				break;
			case 'H':	
				fprintf(out, "\n# Imprime a altura\n");
				altura2(K, out);
				break;
			case 'S' : switch(vet[1]){
					case '\0':
						soma(K, out);
						break;
					case 'A':
						sub_arvore_maior2(K, num1, out);
						break;
					}
				break;
			case 'C' : switch(vet[1]){
					case 'I' : 
						central(K, out); 
						break;
					case 'P' : 
						if(vet[2] == 'O') pos_ordem(K, out); else pre_ordem(K,out); 
						break;
				}
				break;
			}
		}
		
		
		fclose(in);
		fclose(out);	
			
return 0;
}



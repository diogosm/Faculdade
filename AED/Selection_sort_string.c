/* Exercicio_5b -- Algoritmos e Estrutura de Dados I -- Letra b.
   DIOGO SOARES MOREIRA  --  20810205
   Bacharelando em Ciência da Computação
   Universidade Federal do Amazonas  --  UFAM */



#include<stdlib.h>
#include<stdio.h>
#include<string.h>


void selection_sort(char *vet, int tam){

	int a, b, c, exchange;
	char min;

for(a=0; a<tam-1; a++){
	min = vet[a];
	exchange = 0;
	c = a;
		for(b=a+1;b<tam;b++){
			if(vet[b]<min){
				c = b;
				min = vet[b];
				exchange = 1;
			}
		}
	if(exchange){
		vet[c] = vet[a];
		vet[a] = min;
		}
	}
}



int main(){
	int tam;
	char palavra[20];
	char *p = palavra;


printf("Digite a string: ");
gets(palavra);
tam = strlen(palavra);


selection_sort(p, tam);

printf("%s", palavra);
printf("\n\n");
return 0;
}

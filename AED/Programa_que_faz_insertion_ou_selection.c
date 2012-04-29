/* Exercicio_5b -- Algoritmos e Estrutura de Dados I -- Letra b.
   DIOGO SOARES MOREIRA  --  20810205
   Bacharelando em Ciência da Computação
   Universidade Federal do Amazonas  --  UFAM */



#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100



int menu(void){

	int x;

printf("\n\tESCOLHA O MODO DE ORDENAÇÃO: ");
printf("\n\t(1) ORDENA POR SELECAO ");
printf("\n\t(2) ORDENA POR INSERCAO");
printf("\n\t(3) SAIR");
printf("\n\t");

printf("\n\tDigite o num da sua opcao: ");
scanf("%d", &x);

return x;
}






void selection_sort(int vet[], int tam){
	int i, j, min, aux;


for(i=0; i<tam-1; i++){
	min = i;
		for(j=i+1; j<tam; j++){
			if(vet[j]<vet[min]){
				min = j;
			}
		}
	aux = vet[i];
	vet[i] =vet[min];
	vet[min] = aux;
}
}






void insertion_sort(int vet[], int tam){
	int valor, i, j;

for(i=1; i<tam; i++){
	valor = vet[i];
	j=i-1;
while(j>=0 && vet[j]>valor){
	vet[j+1] = vet[j];
	j--;
}
vet[j+1] = valor;
}
}













int main(){
	int vet[MAX];
	int escolha, i;
	int tam;





printf("\t\t***PROGRAMA QUE ORDENA UM VETOR DE INTEIROS***\n\n");

printf("\tDigite o tam do vetor: ");
scanf("%d", &tam);

printf("\n");

for(i=0; i<tam; ++i){
	printf("\n\tDigite os elementos do vetor: ");
	scanf("%d", &vet[i]);
	}




for(;;){
	escolha = menu();
	switch(escolha)
	{
		case 1:
			selection_sort(vet, tam);
			break;
		case 2:
			insertion_sort(vet, tam);
			break;
		case 3:
			exit(0);
	}
printf("\tImpressão do vetor ordenado: \n");
printf("\n\t");
for(i=0; i<tam; i++){
	printf("[%d]", vet[i]);
}
printf("\n\n");
}
printf("\n\n");
return 0;
}

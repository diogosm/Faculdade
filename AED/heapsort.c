#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//pai
int Pai(int i) 
{
	return i/2;
}

//filho esquerdo;
int Esq(int i)	
{
	return 2*i;
}

//filho direito;
int Dir(int i)	
{
	return 2*i + 1;
}


void heapifica(int *heap, int N, int x) 
{
	int aux, maior = x, esq = Esq(x), dir = Dir(x);  		
	
    if(esq <= N && heap[esq] > heap[x])//se o filho for maior q o pai, faz a troca
									//a partir da posicao passada como parametro
	{        
		maior = esq;
	}

	if(dir <= N && heap[dir] > heap[maior])
	{
		maior = dir;
	}


	if(maior != x) // se o indice do pai mudou;
	{
		aux = heap[x];
		heap[x] = heap[maior];
		heap[maior] = aux;

		heapifica(heap, N, maior);
	}
}

void Heap(int heap[tam])						  //coloca todos os pais maiores q os filhos
{   
	int k;

	for(k = (tam/2); k >= 1; k--)
	{
		heapifica(heap, tam-1, k);
	}
}

void heapsort(int *heap, int tamanho)
{     
	int k,tmp;
    int inicio,fim,tempo;
    
    
	Heap(heap);

	for(k = tam-1; k >= 2; k--)
	{
		tmp = heap[1];
		heap[1] = heap[k];
		heap[k] = tmp;

		heapifica(heap, k-1,1);
	}

}

void escreverEmArquivo(char *nomeArquivo)
{
	FILE *file;
	long long int i;
	int  numero;
	int  *vet;
	vet = (int*)malloc(sizeof(int)*tam);
	double inicio, fim, tempo;
	file = fopen(nomeArquivo, "w+b");

	
	if( file == NULL)
	{
		printf("erro ao abrir arquivo\n");
		exit(0);
	}

	
	for(i = 1; i < tam ; ++i)		//escreve caracteres 
	{
		numero =  tam - i;
		fwrite(&numero, sizeof(int), 1, file);
	}
	rewind(file);

	i = 1;
	while(!feof(file))
	{
		fread(&vet[i],sizeof(int),1,file);
		i++;
	}
	
	//imprimindo os valores do primeiro vetor;
	inicio = clock(); 
	heapsort(vet,tam);
	fim = clock();
	tempo = (fim-inicio)/CLOCKS_PER_SEC; // recebendo o tempo ;
	
	
	printf("\n\n");
	printf(" TEMPO HEAP:  %4.4lf\n",tempo);	
	
	fclose(file);	
		
}

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("chamada: ./executavel arquivo.txt\n");
		exit(0);
	}
	
	escreverEmArquivo(argv[1]);
	//LerdoArquivo(argv[1]);
	
return 0;
}



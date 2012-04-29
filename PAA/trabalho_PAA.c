#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define tam 1000000

// MergeSort
void mergesort(int *v,int inicio,int fim) 
{
     int i,j,k,m,*t;
     if (inicio==fim) 
     return;
// ordenacao recursiva das duas metadesr
   m = (inicio+fim)/2;
   mergesort(v,inicio,m);
   mergesort(v,m+1,fim);
// intercalacao no vetor temporario t
   i = inicio;
   j = m+1;
   k = 0;
   t = (int *) malloc(sizeof(int) * (fim-inicio+1));

   while(i<m+1 || j<fim+1) 
   {
   
   if (i == m+1) 
   { // i passou do final da primeira metade, pegar v[j]
   t[k] = v[j];
   j++; 
   k++;
   } 
   else if (j==fim+1) 
   { // j passou do final da segunda metade, pegar v[i]
   t[k] = v[i];
   i++; 
   k++;
   } 
   else if (v[i] < v[j]) 
   { // v[i]<v[j], pegar v[i]
   t[k] = v[i];
   i++;
    k++;
    }
     else 
     { // v[j]<=v[i], pegar v[j]
     t[k] = v[j];
     j++; k++;
     }
     }
// copia vetor intercalado para o vetor original

for(i=inicio;i<=fim;i++)
v[i] = t[i-inicio];
free(t);
}


int partition(int *v,int inicio,int fim) 
{
                  int x,i,j,t;
                  x = v[inicio];    
                  i = inicio - 1;
                  j = fim + 1;
                  for(;;) 
                  {
                  do 
                  { 
                          j--; 
                          } while(v[j]>x);
                          do 
                          {
                                           i++;
                                            } while(v[i]<x);
                                            if (i<j)
                                             {
                                             t = v[i];
                                             v[i] = v[j];
                                             v[j] = t;
                                             }
                                              else
                                              return j;

}
}

void quicksort(int *v,int inicio,int fim) 
{
int q;
if (inicio < fim) 
{
q = partition(v,inicio,fim);
quicksort(v,inicio,q);
quicksort(v,q+1,fim);
}
}




//pai;
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
	int  *vet, *vet2,*vet3;
	vet = (int*)malloc(sizeof(int)*tam);
	vet2 = (int*)malloc(sizeof(int)*tam);
	vet3 = (int*)malloc(sizeof(int)*tam);
	double inicio, fim, tempo, inicio2, fim2, tempo2, inicio3, fim3, tempo3;
	file = fopen(nomeArquivo, "w+b");
	
	if( file == NULL)
	{
		printf("erro ao abrir arquivo\n");
		exit(0);
	}

	
	for(i = 1; i < tam ; ++i)		//escreve caracteres 
	{
		numero =  tam - i;
		//printf(" [%d] ",numero); 
		fwrite(&numero, sizeof(int), 1, file);
	}
	rewind(file);

	i = 1;
	while(!feof(file))
	{
		fread(&vet[i],sizeof(int),1,file);
		//fread(&vet2[i],sizeof(int),1,file);
		//fread(&vet3[i],sizeof(int),1,file);
		i++;
	}
	
	//imprimindo os valores do primeiro vetor;
	inicio = clock(); 
	heapsort(vet,tam);
	fim = clock();
	tempo = (fim-inicio)/CLOCKS_PER_SEC; // recebendo o tempo ;
	
	i = 1;
	while(!feof(file))
	{
		fread(&vet[i],sizeof(int),1,file);
		//fread(&vet2[i],sizeof(int),1,file);
		//fread(&vet3[i],sizeof(int),1,file);
		i++;
	}

	i = 1;
	while(!feof(file))
	{
		fread(&vet[i],sizeof(int),1,file);
		//fread(&vet2[i],sizeof(int),1,file);
		//fread(&vet3[i],sizeof(int),1,file);
		i++;
	}
	//imprimindo os valores do segundo vetor;
	printf("\n\n");	
	inicio2 = clock();i = 1;
	quicksort(vet,1,tam);
	fim2 = clock();
	tempo2 = (fim2-inicio2)/CLOCKS_PER_SEC; //recebendo o tempo;
	
	i = 1;
	while(!feof(file))
	{
		fread(&vet[i],sizeof(int),1,file);
		//fread(&vet2[i],sizeof(int),1,file);
		//fread(&vet3[i],sizeof(int),1,file);
		i++;
	}
	printf("\n\n");
	inicio3 = clock();	
	mergesort(vet,1,tam);
	fim3 = clock();
	tempo3 = (fim3-inicio3)/CLOCKS_PER_SEC;
	
	printf("\n\n");
	printf(" TEMPO HEAP:  %4.4lf\n",tempo);	
	printf(" TEMPO QUICK: %4.4lf\n",tempo2);
	printf(" TEMPO MERGE: %4.4lf\n",tempo3);
	


	
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

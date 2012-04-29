#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define tam 50000000

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

	srand(time(NULL));
	for(i = 0; i < tam ; ++i)		//escreve caracteres 
	{
		numero = rand()%tam;
		fwrite(&numero, sizeof(int), 1, file);
	}
	rewind(file);

	i = 0;
	while(!feof(file))
	{
		fread(&vet[i],sizeof(int),1,file);
		i++;
	}
	

	printf("\n\n");
	inicio = clock();	
	mergesort(vet,0,tam);
	fim = clock();
	tempo = (fim-inicio)/CLOCKS_PER_SEC;
	
	printf("\n\n");
	printf(" TEMPO MERGE: %4.4lf\n",tempo);
	
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

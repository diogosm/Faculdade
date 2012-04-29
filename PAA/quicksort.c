#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define tam 50000000
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
		//printf(" [%d] ",numero); 
		fwrite(&numero, sizeof(int), 1, file);
	}
	rewind(file);

	i = 0;
	while(!feof(file))
	{
		fread(&vet[i],sizeof(int),1,file);
		i++;
	}
	
	//retornando o tempo do quicksort;
	printf("\n\n");	
	inicio = clock();
	quicksort(vet,0,tam);
	fim = clock();
	tempo = (fim-inicio)/CLOCKS_PER_SEC; //recebendo o tempo;
	
	
	printf("\n\n");
	printf(" TEMPO QUICK: %4.4lf\n",tempo);
	
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




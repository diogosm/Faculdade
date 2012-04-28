/*
	Universidade Federal do Amazonas
	1o Trabalho de PAA -- Programação Dinâmica -- Algoritmo de Floyd-Warshall -- Problema de caminho minimo
	NOME : Diogo Soares Moreira
	20810205
*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 5		//tamanho máximo de vértices do grafo


int matriz[MAX][MAX];
//int inf = 1000000;

/* função que cria o grafo de modo randômico */
void criarGrafo(int tam){
	
	int i = 0;
	int j, k;
	k = 1;

	for( ; i < tam ;i++ ){
		for( j = i+1 ; j < tam ; j++ ){
			if ( i==j ) matriz[i][j] = 0;
			else{
				matriz[i][j] = rand()%9+1;
				matriz[j][i] = matriz[i][j];
					
			}
		}
	}
}


void mostrarGrafo(int tam){
	
	int i,j;
	
	for (i=0; i<tam; i++) {
		printf("\n");
		for ( j = 0; j<tam; j++) {
			printf(" %d ", matriz[i][j]);
		}
	} 
}

/* função que realiza o algoritmo floyd-Warshall. Fonte: Cormen */
void floydWarshall(int tam){
	int j, i, k;
	
	for ( k = 0; k < tam; k++ ) {
		for ( i = 0; i < tam; i++ ) {
			for ( j = 0; j < tam; j++ ) {
				if ( matriz[i][j] > ( matriz[i][k] + matriz[k][j] ) ) {
					matriz[i][j] = ( matriz[i][k] + matriz[k][j] );
				}
			}
		}
	}
}


int main(void) {

	int tam = MAX;
	criarGrafo(tam);
	mostrarGrafo(tam);
	floydWarshall(tam);
	getchar();
	printf("\n\n*************************************** RESULTADO ************************************************\n\n");
	getchar();
	mostrarGrafo(tam);
	printf("\n");
	getchar();
	
	return 0;
}

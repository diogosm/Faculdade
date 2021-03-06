/** Trabalho 1 de PAA
    @author = Diogo Soares Moreira
    @date = 28/04/2012
**/

#include <cctype>
#include <map>
#include <utility>
#include <set>
#include <cstdio>
#include <bitset>
#include <cstring>
#include <list>
#include <cmath>
#include <set>
#include <queue>
#include <numeric>
#include <functional>
#include <iterator>
#include <sstream>
#include <stack>
#include <ext/numeric>
typedef long long int llint;
typedef unsigned int uint;
#define hash_map unordered_map
#define hash_set unordered_set
#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <time.h>
#include <ctime>

#define FOR(i,a,b) for( int i = (int)a; i< (int)b; i++)

using namespace std;

int vetorDeCemMil[10000];

int partition(int vet[], int p, int r){
    int x = vet[r];
    int i = p-1;
    for(int j = p; j<r; j++){
        if(vet[j] <= x){
            i++;
            int temp = vet[i];
            vet[i] = vet[j];
            vet[j] = temp;
        }
    }
    int temp2 = vet[i+1];
    vet[i+1] = vet[r];
    vet[r] = temp2;
    return (i+1);
}

/**
    Quicksort based on Cormen version
    Quicksort main function
**/
void quicksort(int vet[], int p, int r){

    if( p<r){
        int q = partition(vet, p, r);
        quicksort(vet, p, q-1);
        quicksort(vet, q+1, r);
    }

}

int main(){


    int testCases = 50;
    double media = 0;
    double vetor[50];
    int u = 0;
    double somaDesvio = 0;
    double DesvioPadrao;

    /** Invoca o quicksort para o Caso de teste com N = 10^4 **/
    while(testCases!=0){
        memset(vetorDeCemMil, 0, sizeof(vetorDeCemMil));
        /** Leitura do vetor **/
        FOR(i,0,10000)
            scanf("%d", &vetorDeCemMil[i]);

        double inicio = clock();
        /** Invoca a funcao quicksort para cada vetor **/
        quicksort(vetorDeCemMil, 0, 10000-1);
        double fim = clock();
        double tempo = (fim-inicio)/CLOCKS_PER_SEC; //recebendo o tempo;
        printf("tempo de execucao do caso #%d:%.20lf\n",(int)fabs(testCases-50)+1,tempo);
        media+=tempo;
        vetor[u] = tempo*tempo;
        somaDesvio += vetor[u];
        u++;
        /** Impress�o dos vetores ordenados **/
        //FOR(i, 0, 10000)
        //    cout<<vetorDeCemMil[i]<<" ";
        //cout<<endl;

        testCases--;
    }
    printf("Media: %.6lf\n", media/50);
    DesvioPadrao = sqrt( (somaDesvio/50) - ((media/50)*(media/50)) );
    printf("Desvio padr�o: %.6lf\n", DesvioPadrao);

    return 0;
}

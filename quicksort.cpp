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

int vetorDeCemMil[100000];

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
    clock_t beg;
    beg=clock();

    int testCases = 50;

    /** Invoca o quicksort para o Caso de teste com N = 10^5 **/
    while(testCases!=0){
        memset(vetorDeCemMil, 0, sizeof(vetorDeCemMil));
        /** Leitura do vetor **/
        FOR(i,0,100000)
            scanf("%d", &vetorDeCemMil[i]);

        /** Invoca a funcao quicksort para cada vetor **/
        quicksort(vetorDeCemMil, 0, 100000-1);

        /** Impressão dos vetores ordenados **/
        //FOR(i, 0, 1000)
        //    cout<<vetorDeDezMil[i]<<" ";
        //cout<<endl;

        testCases--;
    }
    printf("tempo de execucao:%d\n",clock()-beg);

    return 0;
}

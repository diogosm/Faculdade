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
int M = 1000000;

void merge(int vet[], int h, int m, int t){
    int n1 = m-h+1;
    int n2 = t-m;
	int aux[(n1+1)];
	int aux2[(n2+1)];
	/** Cria o arrays L[1..n1+1] e R[1..n2+1]..como descrito no Cormen **/
	FOR(i,0,n1)
        aux[i] = vet[h+i];

    FOR(i,0,n2)
        aux2[i] = vet[m+i+1];

	aux[n1] = M;					//os ultimos elem's de aux e aux2 recebe um valor mto grande. Uma condição de parada pro i e pro j.
	aux2[n2] = M;
	int i = 1;
	int j = 1;

	FOR(k,h,t+1){
		if(aux[i] < aux2[j]) {
			vet[k] = aux[i];
			i++;
		}
		else{
			vet[k] = aux2[j];
			j++;
		}
	}
}

/**
    Mergesort based on Cormen version
    Mergesort main function
**/
void mergesort(int vet[], int head, int tail){

    if(head < tail){
        int m = (head+tail)/2;
		mergesort(vet, head, m);
		mergesort(vet, m+1, tail);
		merge(vet, head, m, tail);
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

        mergesort(vetorDeCemMil,0,100000-1);

        /** Impressão dos vetores ordenados **/
        //FOR(i, 0, 100000)
        //    cout<<vetorDeCemMil[i]<<" ";
        //cout<<endl;

        testCases--;
    }
    printf("tempo de execucao:%d\n",clock()-beg);

    return 0;
}


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

int vetorDeCemMil[1000000];

/**
    Mergesort based on Cormen version
    Mergesort main function
    Vers�o anteriormente implementada por mim e pode ser encontrada em minha p�gina de versionamento : https://github.com/diogosm/Faculdade/tree/master/PAA
**/
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

int main(){
    clock_t beg;
    beg=clock();

    int testCases = 50;

    /** Invoca o quicksort para o Caso de teste com N = 10^5 **/
    while(testCases!=0){
        memset(vetorDeCemMil, 0, sizeof(vetorDeCemMil));
        /** Leitura do vetor **/
        FOR(i,0,1000000)
            scanf("%d", &vetorDeCemMil[i]);

        clock_t beg;
        beg=clock();
        mergesort(vetorDeCemMil,0,1000000);
        printf("tempo de execucao do caso #%d:%d\n",(int)fabs(testCases-50)+1,clock()-beg);
        /** Impress�o dos vetores ordenados **/
        //FOR(i, 0, 10000)
        //    cout<<vetorDeCemMil[i]<<" ";
        //cout<<endl;

        testCases--;
    }
    //printf("tempo de execucao:%d\n",clock()-beg);

    return 0;
}


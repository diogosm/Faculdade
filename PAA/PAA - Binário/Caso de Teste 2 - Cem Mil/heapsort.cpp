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

/**
    Heapsort based on Cormen version
    Heapsort main function
**/
void heapsort(int a[], int n){
   int i = n/2, p, f;
   int t;
   while(1){
      if (i > 0){ i--; t = a[i]; }
      else{
          n--;
          if (n == 0) return;
          t = a[n];
          a[n] = a[0];
      }
      p = i;
      f = i*2+1;
      while (f < n){
          if ((f+1<n) && (a[f+1]>a[f])) f++;
          if (a[f] > t){
             a[p] = a[f];
             p = f;
             f = p*2+1;
          }
          else break;
      }
      a[p] = t;
   }
}

int main(){

    clock_t beg;
    beg=clock();

    int testCases = 50;
    double media = 0;
    double vetor[50];
    int u = 0;
    double somaDesvio = 0;
    double DesvioPadrao;

    /**
        Invoca o quicksort para o Caso de teste com N = 10^5
        N1 = 10^4
    **/
    while(testCases!=0){
        memset(vetorDeCemMil, 0, sizeof(vetorDeCemMil));
        /** Leitura do vetor **/
        FOR(i,0,100000)
            scanf("%d", &vetorDeCemMil[i]);

        clock_t beg;
        double inicio=clock();
        heapsort(vetorDeCemMil, 100000);
        double fim = clock();
        double tempo = fabs((fim-inicio)/CLOCKS_PER_SEC); //recebendo o tempo;
        printf("tempo de execucao do caso #%d:%4.10lf\n",(int)fabs(testCases-50)+1,tempo);
        media+=tempo;
        vetor[u] = tempo*tempo;
        somaDesvio += vetor[u];
        u++;
        /** Impressão dos vetores ordenados **/
        //FOR(i, 0, 100000)
        //    cout<<vetorDeCemMil[i]<<" ";
        //cout<<endl;

        testCases--;
    }
    //printf("tempo de execucao:%d\n",clock()-beg);

    printf("Media: %.6lf\n", media/50);
    DesvioPadrao = sqrt( (somaDesvio/50) - ((media/50)*(media/50)) );
    printf("Desvio padrão: %.6lf\n", DesvioPadrao);

    return 0;
}

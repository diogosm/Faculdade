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

/**
    Heapsort based on Cormen version & wikipedia English version
    Heapsort main function
**/
void heapsort(int a[], int n){
   int i = n/2, p, f;
   int t;
   while(1){
      if (i > 0){ i--; t = a[i]; }
      else{
          n--;
          if (n == 0) return;   //alacancou o tamanho minimo entao...vetor ordenou :p
          t = a[n];
          a[n] = a[0];
      }
      p = i; f = i*2+1;
      /** Swap no vetor até que o filho seja menor q o tamanho **/
      while (f < n){
          if ((f+1<n) && (a[f+1]>a[f])) f++;
          if (a[f] > t){
             a[p] = a[f];
             p = f; f = p*2+1;
          }
          else break;
      }
      a[p] = t;
   }
}

int main(){



    int testCases = 50;

    /**
        Invoca o quicksort para o Caso de teste com N = 10^5
        N1 = 10^4
    **/
    while(testCases!=0){
        memset(vetorDeCemMil, 0, sizeof(vetorDeCemMil));
        /** Leitura do vetor **/
        FOR(i,0,10000)
            scanf("%d", &vetorDeCemMil[i]);

        clock_t beg;
        beg=clock();
        heapsort(vetorDeCemMil, 10000);
        printf("tempo de execucao do caso #%d:%d\n",(int)fabs(testCases-50)+1,clock()-beg);
        /** Impressão dos vetores ordenados **/
        //FOR(i, 0, 10000)
        //    cout<<vetorDeCemMil[i]<<" ";
        //cout<<endl;

        testCases--;
    }

    return 0;
}

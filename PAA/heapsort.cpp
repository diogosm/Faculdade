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
   int i = n/2, pai, filho;
   int t;
   for (;;){
      if (i > 0){
          i--;
          t = a[i];
      }
      else{
          n--;
          if (n == 0) return;
          t = a[n];
          a[n] = a[0];
      }

      pai = i;
      filho = i*2 + 1;

      while (filho < n){
          if ((filho + 1 < n)  &&  (a[filho + 1] > a[filho]))
              filho++;
          if (a[filho] > t){
             a[pai] = a[filho];
             pai = filho;
             filho = pai*2 + 1;
          }
          else
             break;
      }
      a[pai] = t;
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

        heapsort(vetorDeCemMil, 100000);

        /** Impressão dos vetores ordenados **/
        //FOR(i, 0, 100000)
        //    cout<<vetorDeCemMil[i]<<" ";
        //cout<<endl;

        testCases--;
    }
    printf("tempo de execucao:%d\n",clock()-beg);



    return 0;
}

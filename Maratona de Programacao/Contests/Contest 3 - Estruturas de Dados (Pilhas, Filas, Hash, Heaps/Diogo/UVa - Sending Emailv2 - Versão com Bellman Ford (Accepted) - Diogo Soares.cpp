#include <cstdio>
#include <iostream>
#include <bitset>
#include <cstring>
#include <list>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
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
#include<iostream>
#include<math.h>
#include<vector>
#include<string>
#include<stdlib.h>
#include<stdio.h>
#include<algorithm>
using namespace std;

//#define INFINITO 74000
#define NODOS 20005
#define ARESTAS 100010
#define INF 1<<30

typedef struct{
    int de;
    int para;
    int peso;
} Aresta;

Aresta arestas[ARESTAS];
int distancia[NODOS];

void bellmanFord(int numArestas, int numNodos, int source){
    int trocou;
    for(int i = 0 ; i<numNodos; i++){       /** inicializa o peso das distancias com INFINITO **/
        distancia[i] = INF;
    }
    distancia[source] = 0;
    for(int i =0 ; i<numNodos; i++){        /** Ajusta as arestas **/
        trocou = 0;
        for(int j = 0; j< numArestas; j++){
            if( distancia[arestas[j].para] > distancia[arestas[j].de] + arestas[j].peso  ){
                distancia[arestas[j].para] = distancia[arestas[j].de] + arestas[j].peso;
                trocou = 1;
            }
        }
        if(trocou==0) break;
    }

    /** TeSTE **/
    //for(int i = 0;i<numNodos;i++){
    //    cout<<"Distancia entre o nodo fonte "<<source<<" e "<<i<<" eh = "<<distancia[i]<<endl;
    //}
}

int main(){

    int T;
    int testCases = 1;
    scanf("%d", &T);
    while(T!=0){
        int n, m,s,t;
        scanf("%d %d %d %d", &n, &m, &s, &t);
        for(int i = 0;i<m*2;i=i+2){
            int a,b,c;
            scanf("%d %d %d", &a, &b, &c);
            arestas[i].de = a;
            arestas[i].para = b;
            arestas[i].peso = c;
            arestas[i+1].de = b;
            arestas[i+1].para = a;
            arestas[i+1].peso = c;
        }   /** leitura do grafo **/
        if(m>0){
            bellmanFord(m*2,n,s);
            if(distancia[t] == INF){ printf("Case #%d: unreachable\n", testCases); }
            else{ printf("Case #%d: %d\n", testCases, distancia[t]); }
        }
        else{ printf("Case #%d: unreachable\n", testCases); }
        testCases++;
        T--;
    }

    return 0;

}

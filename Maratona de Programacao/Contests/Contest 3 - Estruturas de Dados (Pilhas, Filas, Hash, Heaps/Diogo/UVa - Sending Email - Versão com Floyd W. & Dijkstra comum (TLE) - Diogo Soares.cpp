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
using namespace std;
using namespace __gnu_cxx;
typedef pair<int,int> pii;
typedef long long int llint;
#define FOR(i,a,b) for(int i = (int)a;i<(int)b;i++)
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

#define INFINITO 74000

int grafo[20000][20000];
int dist[20000];
int otimo[20000];


void floydWarshall( int n )
{
    int i, j, k;
    
    for ( k = 0; k < n; k++ )
    {
        for ( i = 0; i < n; i++ )
        {
            for ( j = 0; j < n; j++ )
            {
                if ( grafo[i][j] > grafo[i][k]+grafo[k][j] )
                {
                    grafo[i][j] = grafo[i][k]+grafo[k][j];
                }
            }
        }
    }
}

void dijkstra( int origem, int destino, int n )
{
    int i, menor, atual, u, j;
    
    for ( i = 0; i < n; i++ )
    {
        dist[i] = INFINITO;
        otimo[i] = 0;
    }
    dist[origem] = 0;

    while ( ! otimo[destino] )
    {
        menor = INFINITO;
        /* Busca o mais próximo que ainda não seja ótimo */
        for ( i = 0; i < n; i++ )
        {
            if ( dist[i] < menor && ! otimo[i] )
            {
                menor = dist[i];
                u = i;
            }
        }
        if ( menor == INFINITO ) break;
        
        otimo[u] = 1;
        
        /* Faz o relaxamento dos pesos dos adjacentes a u */
        for ( i = 0; i < n; i++ )
        {
            if ( dist[i] > dist[u]+grafo[u][i] )
            {
                dist[i] = dist[u]+grafo[u][i];
            }
        }
    }
}




int main(){

	int N;
	int caso = 1;
	int a,b,c,n,m;
	int s,t;	/** Origem S e destino T **/
	scanf("%d", &N);
	while(N!=0){
		memset(grafo, INFINITO, sizeof(grafo));
		scanf("%d %d %d %d", &n, &m, &s, &t);
		for(int i = 0;i<m;i++){
			scanf("%d %d %d", &a, &b, &c);
			grafo[a][b] = c;
			grafo[b][a] = c;
		}

		/** Usando floyd Warshall toma TLE FUDIDO!!!  kkkk **/
		//floydWarshall(n);

		dijkstra(s,t,n);
		
		for(int k = 0;k<n;k++){
			for(int u = 0;u<n;u++){
				cout<<grafo[k][u]<<" "; 
			}
			cout<<endl;
		}

		//printf("Distancia entre S e T = %d\n", grafo[s][t]);
		if(grafo[s][t] < INFINITO){
			printf("Case #%d: %d\n", caso, grafo[s][t]);		
		} else { printf("Case #%d: unreachable\n", caso); }
		N--;
		caso++;
	}
                                                                                                                                                                                return 0;
}



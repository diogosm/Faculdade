#include <stdio.h>

#define MAX_CIDADES 500
#define INFINITO 2000

int cidades[MAX_CIDADES][MAX_CIDADES];
int dist[MAX_CIDADES];
int otimo[MAX_CIDADES];

/** Complexidade N^3 aproximadamente **/
/*
* Menor caminho entre todos os pares
*/
void floydWarshall( int n )
{
    int i, j, k;
    
    for ( k = 0; k < n; k++ )
    {
        for ( i = 0; i < n; i++ )
        {
            for ( j = 0; j < n; j++ )
            {
                if ( cidades[i][j] > cidades[i][k]+cidades[k][j] )
                {
                    cidades[i][j] = cidades[i][k]+cidades[k][j];
                }
            }
        }
    }
}

/** Complexidade N log N aproximadamente **/
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
            if ( dist[i] > dist[u]+cidades[u][i] )
            {
                dist[i] = dist[u]+cidades[u][i];
            }
        }
    }
}

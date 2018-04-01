#include <stdio.h>

#define MAX_CIDADES 500
#define INFINITO 2000

int cidades[MAX_CIDADES][MAX_CIDADES];
int dist[MAX_CIDADES];
int otimo[MAX_CIDADES];

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

int main()
{
    int i, j;
    int x, y, h;
    int n, e;
    int k, o, d;
    FILE* arq = stdin;
   
    fscanf( arq, "%d %d", &n, &e );
    
    while ( n != 0 )
    {
        for ( i = 0; i < n; i++ )
        {
            for ( j = 0; j < n; j++ )
            {
                cidades[i][j] = INFINITO;
            }
        }
    
        for ( i = 0; i < e; i++ )
        {
            fscanf( arq, "%d %d %d", &x, &y, &h );
            
            cidades[x-1][y-1] = h;
        }
        
        for ( i = 0; i < n; i++ )
        {
            for ( j = 0; j < n; j++ )
            {
                if ( cidades[i][j] != INFINITO && cidades[j][i] != INFINITO )
                {
                    cidades[i][j] = 0;
                    cidades[j][i] = 0;
                }
            }
        }
        
      //  floydWarshall( n );
        
        fscanf( arq, "%d", &k );

        for ( i = 0; i < k; i++ )
        {
            fscanf( arq, "%d %d", &o, &d );
            
            dijkstra( o-1, d-1, n );
            
            if ( dist[d-1] != INFINITO )
                printf( "%d\n", dist[d-1] );
            else
                printf( "Nao e possivel entregar a carta\n" );
            
//            if ( cidades[o-1][d-1] != INFINITO ) printf( "%d\n", cidades[o-1][d-1] );
  //          else printf( "Nao e possivel entregar a carta\n" );
        }
        
        printf( "\n" );
        
        fscanf( arq, "%d %d", &n, &e );
    }
}

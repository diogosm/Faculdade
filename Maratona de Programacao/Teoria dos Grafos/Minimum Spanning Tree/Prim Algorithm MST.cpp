/*
 * Gera a arvore espalhada minima de um grafo
*/

int INFI = 100*100;
int matriz[N][N];
int pais[N];

void prim(int n,int m){         //N vertices, M Arestas
     for(int i = 0;i<n;i++) pais[i] = -1;
     pais[0] = 0;           //Array pais guarda todos os caminhos da árvore iniciando em  nodo 0
     while(true){
     
                 int minCusto = INFI;
                 int v0,w0;
                 
                 for(int i = 0;i<n;i++){
                         if(pais[i]==-1){
                                  for(int j = 0;j<n;j++){
                                          if(pais[j]!=-1 && minCusto > matriz[i][j]){ 
                                                         minCusto = matriz[i][j]; v0=i; w0=j; 
                                          }
                                  }                
                         }        
                 }            
                 if(minCusto == INFI) break;            //Se um caminho menor não é mais achado, então a árvore geradora já foi achada.
                 pais[v0] = w0;                         //P/ cada nó retorna o pai dele no array pais.     
     } 
}

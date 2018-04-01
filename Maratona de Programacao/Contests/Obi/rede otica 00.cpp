#include<stdio.h>
#include <string.h>
#include<string>
#include<vector>
#include<set>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<map>
#include<iostream>
#include <algorithm>

using namespace std;

#define N 100

int INFI = 100*100;
int matriz[N][N];
int pais[N];
vector<pair<int,int> > vet;

void prim(int n,int m){
     for(int i = 0;i<n;i++) pais[i] = -1;
     pais[0] = 0;
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
                 if(minCusto == INFI) break;
                 pais[v0] = w0;                 
     } 
}

int main()
{
    int n,m;
    int inst = 1;
    while(scanf("%d%d",&n,&m) && n!=0){
          //memset(matriz,INFI,sizeof(matriz));
          printf("Teste %d\n",inst++);
          for(int i =0;i<n;i++){
                  for(int j = 0;j<n;j++){
                          matriz[i][j] = INFI;       
                  }        
          }  
          for(int i = 0;i<m;i++){
                  int a,b,c;
                  scanf("%d%d%d",&a,&b,&c);        
                  a--; b--;
                  matriz[a][b] = c;
                  matriz[b][a] = c;
          }      
          prim(n,m);  
          //for(int i =0;i<n;i++){
                  //for(int j = 0;j<n;j++){
                          //printf("%d ", matriz[i][j]);        
                  //}        
                  //printf("\n");
          //}   
          //for(int i = 0;i<n;i++){
                  //printf("%d ",pais[i]);
          //}     
          
          for(int i = 1;i<n;i++){
                  int a = min(i+1,(pais[i]+1));
                  int b = max(i+1,(pais[i]+1));
                  pair<int,int> p = make_pair(a,b);
                  vet.push_back(p);     
          }
          sort(vet.begin(),vet.end());
          for(int i = 0;i<vet.size();i++){
                  printf("%d %d\n",vet[i].first,vet[i].second);        
          }
          printf("\n");
          vet.clear();  
          //printf("\nINFI %d\n", INFI);
    }
}






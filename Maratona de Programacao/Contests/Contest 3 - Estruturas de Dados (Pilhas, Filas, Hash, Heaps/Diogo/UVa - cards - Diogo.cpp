#include<stdio.h>
#include<map>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<queue>
#include<stack>

using namespace std;

int main(){
 
    int n,teste;
    while(scanf("%d", &n) && n!=0){
         
         if(n!=1){
                  queue<int> fila;
                  deque<int> pilha;
                  for(int i = n;i>0;i--){   /** add na pilha os valores das cartas **/
                          pilha.push_front(i);
                  }
                  int i = 0;
                  while(fila.size() != n-1){
                                    int k = pilha.front();
                                    fila.push(k);             //add topo da pilha na fila
                                    pilha.pop_front();
                                    int u = pilha.front();
                                    pilha.push_back(u);       //add prox elemento no fim da pilha
                                    pilha.pop_front();
                  }
                  printf("Discarded cards: ");
                  cout<<fila.front();
                  fila.pop();
                  while(!fila.empty()){
                                       cout<<", ";
                                       cout<<fila.front();
                                       fila.pop();
                  }
                  printf("\n");
                  printf("Remaining card: %d\n",pilha.front());
         }else{   /** caso o numero de cartas seja 1 imprime direto :p **/
                  printf("Discarded cards:\n");    
                  printf("Remaining card: 1\n"); 
         }
                           
    }   
    
    return 0;
}

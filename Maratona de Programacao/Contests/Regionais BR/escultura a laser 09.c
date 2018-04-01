#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main(){
    
    int a,c;
    while(scanf("%d %d",&a,&c) && a!=0){
         
         int vet[10000+1];
         int i;
         int qtd=0;
         for(i=0;i<c;i++)
             scanf("%d",&vet[i]);
             
         for(i=0;i<c-1;i++){
             if(vet[i+1]>vet[i]){
                  qtd+=vet[i+1]-vet[i];
             }                 
         } 
         if(a-vet[c-1]>0) qtd+=(a-vet[c-1]);
         printf("%d\n",qtd);
                                   
    }
    
    return 0;    
}

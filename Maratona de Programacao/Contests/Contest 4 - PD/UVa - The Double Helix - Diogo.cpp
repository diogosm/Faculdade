#include <cstdio>
#include <list>
#include <vector>
#include <iostream>
#include <ctime>
#include <stdio.h>
#include <string.h>

using namespace std;

int VALRETURN = 0;
int h1[10000];
int h2[10000];
int pontosI[10000];
int soma;

int buscaBin(int valor, int *h1, int fin, int ini){
    VALRETURN = 0;
    int mid = fin+ini;
    mid /= 2;
    //cout<<"SHOW "<<(int)h1[mid]<<" "<<(int)valor<<endl;
    if( (int)h1[mid] == (int)valor){ VALRETURN = 1; return 2; }

    if(fin>ini){

         if(h1[mid] > valor){
              buscaBin(valor, h1, mid-1, ini);
         }else{
              buscaBin(valor, h1, fin, mid+1);
         }

    }
    return 0;

}

void resolve(int i, int j, int cont, int qtdePontos, int tamh1, int tamh2){

    int soma1,soma2,k, X;
    soma1 = soma2 = 0;

    if(i>=tamh1 && j>= tamh2) return;

    if(cont>=qtdePontos){ X = 10001; }
    else{ X = pontosI[cont]; }

    for(k = i; h1[k]!= X && k<tamh1-1; k++){
        soma1 += h1[k];
    }
    soma1 += h1[k];
    i = k+1;
    for(k = j; h2[k]!=X && k<tamh2-1; k++){
        soma2 += h2[k];
    }
    soma2 += h2[k];
    j = k+1;
    if(soma1>soma2){ soma += soma1; }
    else{ soma += soma2; }
    //cout<<i<<" "<<j<<endl;
    //cout<<soma<<endl;
    resolve(i,j, cont+1, qtdePontos, tamh1, tamh2);
}


int main(int argc, char **argv) {

    clock_t beg;
    beg=clock();
	int n,k, pontos;

    while(scanf("%d", &n) && n!=0){
         memset(h1, 0, sizeof(h1));
         memset(h2, 0, sizeof(h2));
         pontos = 0;
         for(int i = 0;i<n;i++){
                 scanf("%d", &h1[i]);
         }
         scanf("%d", &k);
         for(int i = 0;i<k;i++){
                 scanf("%d", &h2[i]);
                 if( buscaBin(h2[i], h1,n, 0) || VALRETURN == 1 ){
                      //cout<<"LOL"<<endl;
                      pontosI[pontos++] = h2[i];
                      //printf("interseccao %d\n", h2[i]);
                 }
         }
         //for(int i = 0; i<pontos ; i++)
            //cout<<pontosI[i]<<" ";
         //n = helix 1 e  k = helix 2
        soma = 0;
        resolve(0,0,0, pontos, n,k);
        cout<<soma<<endl;

    }

    //printf("tempo de execução:%d\n",clock()-beg);
	return 0;
}

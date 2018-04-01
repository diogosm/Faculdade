#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<string>
#include<string.h>
#include<map>
#include<cmath>

using namespace std;

//int vet[99000000+1];

int main(){

	//99000000
	//10000000
	/*
	vet[0] = 1;
	vet[1] = 1;
	vet[2] = 1;
	vet[3] = 3;
	*/
	/** Solucao O(1) com PD
	for(int i = 4;i<=99000000;++i){
		if(i & 1){
			vet[i] = (vet[i/2]*2)+1;
		}else{
			vet[i] = (vet[i/2]*2)-1;
		}
	}
	**/

	while(1){
		string k;
		int n,atual=0;
		
		cin>>k;
		
		
		if(k == "00e0") break;
		
		n = (int)k[0]-48;
		n *= 10;
		n += (int)k[1]-48;
		
		for(int i = 0;i<(int)k[3]-48;++i){
			n *= 10;
		} /** Leitura do valor n. **/
	
		if(n==1){
			printf("1\n");
		}else{
			/** Solução linear 
			for(int i = 2;i<=n;++i){
				atual = (atual+2)%i;
			}
			printf("%d\n",atual+1);
			**/
			int res = 1+2*n;
			int lol = pow(2,(1+(int)log2(n)));
			res -= lol;
			printf("%d\n",res);
		}
	}

	return 0;
}

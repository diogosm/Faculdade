#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<cstring>

using namespace std;

char k[10005];
int LCP[10005];

struct sufix{
	string k;
	int index;
} sufixArray[1000005];

bool compara(struct sufix a, struct sufix b){
	return a.k<b.k;
}

int main(){

	int t;
	cin>>t;
	while(t!=0){
		scanf("%s", k);

		for(int i = 0; i<strlen(k);i++){
			sufixArray[i].k = k+i;
			sufixArray[i].index = i;
		}
		/** Gera uma sufix array ordenada lexicograficamente **/
		sort(sufixArray, sufixArray+strlen(k), compara);

		LCP[0] = 0;
		/**
			Gera a LCP Table
			Para cada 2 strings na suffix array,
			mostre o máximo que ela é comum na string
		**/
		int aux = -1;
		int indiceMaior = -1;
		for(int i = 1; i<strlen(k);i++){
			int x,w,j;
			x=0;
			w = sufixArray[i].index;
			j = sufixArray[i-1].index;
			while(w<strlen(k) && j<strlen(k)){
				if(k[w]==k[j]){ x++; }
				else{ break; }
				w++; j++;
			}
			if(x>aux){
				aux = x;
				indiceMaior = sufixArray[i].index;
			}
			LCP[i] = x;
		}

		if(aux <= 0){
			printf("No repetitions found!\n");
		} else {
			string maior;
			for(int i = indiceMaior; i<indiceMaior+aux; i++)
				maior += k[i];

			int j = 0;
			for(int i = 0; i<strlen(k)-aux+1; i++){
				if(k[i] == maior[0]){
					int loop = 0;
					for(int u = 1; u<maior.size(); u++){
						if(k[i+u] == maior[u]) loop++;
					}
					if(loop==aux-1){
						j++;
					}
				}
			}
			cout<<maior<<" "<<j<<endl;
		}
		/**
		for(int i =0; i<strlen(k);i++){
			cout<<LCP[i]<<" "<<sufixArray[i].k<<" "<<sufixArray[i].index<<" Indice maior:"<<indiceMaior<<" Tamanho da string:"<<aux<<endl;
		}
		**/
		t--;
	}

	return 0;
}




#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;
string line;

int vet[2000][2000];

/** Usa PD pra construir a tabela LCS usando memorization **/
void lcs(string a, string b){
	int m,n;
	m = a.size();
	n = b.size();
	for(int i = 1; i<=m; i++){
		for(int j = 1; j<=n; j++){
			if(a[i-1] == b[j-1]){
				vet[i][j] = vet[i-1][j-1]+1;
			}
			else{
				vet[i][j] = max(vet[i-1][j], vet[i][j-1]);
			}
		}
	}
}

int main(){

	string a,b;

	while(getline( std::cin, line )){
		a = line;
		memset(vet,-1,sizeof(vet));
		getline( std::cin, line );
		b = line;
		int n,m;
		n = a.size();
		m = b.size();
		lcs(a,b);
		//for(int i = 0;i<=n;i++){
		//	for(int j = 0;j<=m;j++){
		//		cout<<vet[i][j]<<" ";
		//	}
		//	cout<<endl;
		//}
		printf("%d\n", 1+vet[n][m]);
	}

	return 0;
}

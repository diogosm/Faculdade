#include<vector>
#include<string.h>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>

using namespace std;

int main(){

	int t;
	scanf("%d", &t);
	while(t!=0){


		vector<int> H;
		vector<int> M;

		int n;
		scanf("%d", &n);
		for(int i = 0; i<n; i++){
			int x;
			cin >> x;
			H.push_back(x);
		}

		for(int i = 0; i<n; i++){
			int x;
			cin >> x;
			M.push_back(x);
		}

		sort(H.begin(), H.end());
		sort(M.begin(), M.end());
		int soma = 0;
		for(int i = 0; i<n; i++){
			soma += H[i]*M[i];
		}
		printf("%d\n", soma);

		t--;
	}

	return 0;


}

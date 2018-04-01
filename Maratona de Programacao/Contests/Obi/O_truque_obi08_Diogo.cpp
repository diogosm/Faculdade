#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<set>

using namespace std;

int main(){

	int n;
	string x;
	vector<string> cartas;
	vector<string> res;
	
	scanf("%d", &n);

	for( int i=0;i<n;i++){
		cin>>x;
		cartas.push_back(x);
	}

	x = "vazio";
	for( int i=0;i<n;i++)
		res.push_back(x);	

	//Funcao de print teste
	//for(int i =0;i<n;i++){
		//cout<<res[i]<<" "<<cartas[i]<<endl;
	//}	

	int k=0;
	int a,j;
	for(int i =0;i<n;i++){
		int size = cartas[i].size();
		size+=k;
		j = k;
		while(j<size){
			a = j%n;
			if(res[a] != "vazio"){ size++; }
			j++;
		}
		a = (j-1)%n;
		//k = j;
		k = a+1;
		res[a] = cartas[i];
		//cout<<a<<" "<<res[a]<<endl;
	}

	for(int i = 0;i<n;i++){
		cout<<res[i]<<endl;
	}
	
	return 0;
}

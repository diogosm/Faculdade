#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){

	while(1){
	
		int n;
		string k;
		scanf("%d",&n);
		if(n==0) break;
		
		cin>>k;
		//3
		//"t" tyoh "hi" enee "si" aabs "s"
		//cout<<k.size()<<endl; 
		vector< vector<char> > v;
		int boolean = 1;
		
		for(int i = 0;i<k.size()/n;i++){
			vector<char> aux;
			for(int j = i*n;j<n*(i+1);j++){
				aux.push_back(k[j]);
			}
			if(boolean & 1){
				boolean++;
			}else{
				reverse(aux.begin(),aux.end());
				boolean++;
			}
			//for(int k = 0;k<aux.size();k++){
				//cout<<aux[k]<<" ";
			//}
			//cout<<endl;
			v.push_back(aux);
		}
		
		for(int i = 0;i<n;i++){
			for(int j = i;j<k.size();j=j+n){
				//cout<<j<<" ";
				vector< vector<int> >::size_type u = j/n;
				vector<int>::size_type x = i;
				cout<<v[u][x];
			}
		}
		cout<<endl;

	}

	return 0;
}

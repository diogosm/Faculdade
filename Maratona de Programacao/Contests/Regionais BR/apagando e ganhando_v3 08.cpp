#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<sstream>
#include<vector>
#include<map>
#include<string.h>
#include<set>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;

int main(){

	while(1){
		int n,d;
		string k;
		scanf("%d %d",&n, &d);
		
		if(n==0 && d==0) break;
		cin>>k;

		int vet[n];
		deque<int> q;
		vector<int> v;
		int cont=0;	/** Conta "delecoes" **/
		//memset(vet,0,sizeof(vet));
		int i,j = 0;
		int last = 1;
		int dig = (int)(k[0]-'0');
		q.push_back(dig);

		for(i =1;i<k.size();++i){
			
			int digit = (int)(k[i]-'0');
			//cout<<digit<<endl;
			while(q.size()>0 && q.back()<digit){
				int digit2 = q.back();
				if(v.size()<d){
					//cout<<"Removido "<<digit2<<endl;
					v.push_back(digit2);
					//if(v.size() == d) break;
					q.pop_back();
				} else { break; }
			}
			//if(v.size() == d) break;
			q.push_back(digit);
			//if(q.size() == n-d) break;
		}
		
		if(q.size()>=n-d){
			for(int u = 0;u<(n-d);++u){
				cout<<q[u];
			}
			cout<<endl;
		} //else {
			//cout<<endl;
		//}
		
		/*
		for(int u = 0;u<q.size();u++){
			cout<<q[u];
		}
		cout<<" ";
		for(int u = 0;u<v.size();u++){
			cout<<v[u];
		}
		cout<<endl;
		*/
	}

	return 0;
}

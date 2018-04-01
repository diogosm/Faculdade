#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<map>
#include<vector>
#include<set>
#include<cmath>
#include<math.h>
#include<string.h>
#include<string>
#include<iostream>

using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;++i)

int vet[100000+2];

int main(){

	int n;
	scanf("%d",&n);

	memset(vet,0,sizeof(vet));
	FOR(i,0,n)
		scanf("%d",&vet[i]);

	int q;
	scanf("%d",&q);
	FOR(i,0,q){
		string query;
		int a,b;
		
		cin>>query;
		scanf("%d %d",&a,&b);
		//cout<<query<<endl;
		
		if(query == "U"){ vet[a-1] = b; }
		else{
			int m1,m2;
			m1 = a-1;
			FOR(j,a,b){
				if(vet[j]>vet[m1]) m1 = j;
			}
			m2 = -1;
			FOR(j,a-1,b){
				if(j!=m1) m2 = max(m2,vet[j]);
			}
			printf("%d\n",vet[m1]+m2);
		}
	}

	return 0;
}

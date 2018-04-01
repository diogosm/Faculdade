#include<stdio.h>
#include<stdlib.h>
#include<map>
#include<set>
#include<iostream>
#include<iostream>
#include<math.h>
#include<cmath>
#include<algorithm>
#include<string>

using namespace std;

map<int,int> m;

int main(){

	int n;
	scanf("%d",&n);

	for(int i = 0; i<n;i++){
		int x;
		scanf("%d", &x);
		m[x]++;
	}
	int max = -1;
	int cand = -1;
	for( map<int,int>::iterator it = m.begin(); it!=m.end();it++ ){

		if((*it).second>max){ max = (*it).second; cand = (*it).first; }

	}

	printf("%d\n", cand, max);

	return 0;
}

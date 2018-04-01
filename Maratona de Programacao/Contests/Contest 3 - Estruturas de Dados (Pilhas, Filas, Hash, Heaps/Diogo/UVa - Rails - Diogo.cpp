#include <cstdio>
#include <iostream>
#include <bitset>
#include <cstring>
#include <list>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <numeric>
#include <functional>
#include <iterator>
#include <sstream>
#include <stack>
#include <ext/numeric>
using namespace std;
using namespace __gnu_cxx;
typedef pair<int,int> pii;
typedef long long int llint;
typedef unsigned int uint;
#define hash_map unordered_map
#define hash_set unordered_set
#include<iostream>
#include<math.h>
#include<vector>
#include<string>
#include<stdlib.h>
#include<stdio.h>
#include<algorithm>
using namespace std;

int main(){

	int n;
	int k;

	while(scanf("%d", &n) && n!=0){

		int station[900001];

		while(scanf("%d", &k) && k!=0){
			int j = 1;
			int start = 0;
			int comb = 1;
			for(int i = 1;i<n;i++){
				for( ;j<=k;j++){
					station[start] = j;
					start++;
					//cout<<station[start-1]<< " "<<j<<" "<<station[start-1]<<endl;	
				}
				if( start < 1 || station[start-1] != k){
					comb = 0;
					start--;
				}
				else{ start--; }

				scanf("%d", &k);
			}
			//cout<<"j start k comb "<<j<<" "<<start<<" "<<k<<" "<<comb<<endl;
			if( j!=k && (start<1 || station[start-1] != k)) comb = 0;
			if(comb == 0){ printf("No\n"); }
			else{ printf("Yes\n"); }
			
		} 
		printf("\n");
	}

	return 0;
}



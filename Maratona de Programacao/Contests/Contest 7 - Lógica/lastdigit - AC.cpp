#include<bitset>
#include<cmath>
#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>
#include<algorithm>
using namespace std;
typedef unsigned long long int llint;

llint bigmod( llint b, llint p, llint m){
   llint a;
   if (p == 0) return 1;
   if (p%2 == 0){
      a=bigmod(b,p/2,m);
      return (a*a)%m;
   }else{
      return ((b%m)*bigmod(b,p-1,m))%m;
   }
}

int main(){

	int n;
	scanf("%d",&n);
	for( ; n>0 ; --n){
		llint a,b;
		string k;
		cin>>k;
		a = (int)k[k.size()-1]-48;
		scanf("%lld",&b);
		if(b!=0){
			llint res = bigmod(a,b,10);
			printf("%lld\n",res);
		}else{
			if(a == 0 && b == 0){ printf("1\n"); }
			else{ printf("1\n"); }
		}
	}

	return 0;
}

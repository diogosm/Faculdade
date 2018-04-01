#include<vector>
#include<string>
#include<stdlib.h>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<math.h>
#include<iostream>

using namespace std;

unsigned long long int reverse(unsigned long long int num){
	unsigned long long int result = 0;
	unsigned long long int k = 1;
	unsigned long long int aux = num;
	while( num>0 ){
		//result += (num%10)*k;
		num /= 10;		
		k *= 10;
	}
	k /= 10;
	while( aux>0 ){
		result += (aux%10)*k;
		aux /= 10;
		k /= 10;
	}
	return result;
}

int main(){

	int t;
	scanf("%d", &t);
	while(t!=0){

		unsigned long long int a,b;
		scanf("%lld %lld", &a, &b);
		
		unsigned long long int k;
		k = reverse(a)+reverse(b);
		printf("%lld\n", reverse(k));
		t--;
	}

	return 0;
}


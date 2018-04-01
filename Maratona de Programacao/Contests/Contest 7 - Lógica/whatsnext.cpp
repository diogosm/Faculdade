#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<iostream>
#include<sstream>
#include<algorithm>

using namespace std;

int main(){

	while(1){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		if(a==0 && b==0 && c==0) break;
		
		/** PA **/
		if( (c-b)==(b-a) ){
			printf("AP %d\n", c+(b-a));
		}else{
			printf("GP %d\n", c*(b/a));
		}
	
	}

	return 0;
}

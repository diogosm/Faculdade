#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main(){

	int n;
	int casos = 1;
	while(scanf("%d",&n)){
		if(n==0) break;
		printf("Teste %d\n%d\n\n",casos++,(int)pow(2,n)-1);	
	}

	return 0;
}

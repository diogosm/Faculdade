#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main(){

	int n;
	int casos = 1;
	while(scanf("%d",&n) && n!=0){

		int i,j,k,l;
		i = n/50;
		n = n - i*50;
		j = n/10;
		n = n - j*10;
		k = n/5;
		n = n - k*5;
		l = n;
		printf("Teste %d\n%d %d %d %d\n\n", casos,i,j,k,l); 
		casos++;

	}

	return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main(){

	int n;
	int casos = 1;
	while(scanf("%d",&n) && n!=0){
		int res,i;
		res = 0;
		int boolean = 1;
		for(i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			if(x==i && boolean==1){ res = i; boolean = 0; }
		}
		printf("Teste %d\n%d\n\n",casos,res);
		casos++;
	}

	return 0;
}

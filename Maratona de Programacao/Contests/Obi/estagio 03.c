#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main(){

	int n;
	int casos = 1;
	while(scanf("%d",&n)){
		if(n==0) break;
		printf("Turma %d\n",casos);
		int vet[1001][2];
		int i;
		int max = -1;
		for(i=0;i<n;i++){
			int x,y;
			scanf("%d %d", &x, &y);
			vet[i][0] = x;
			vet[i][1] = y;
			if(y>max) max = y;
		}
		for(i=0;i<n;i++){
			if(vet[i][1] == max) printf("%d ",vet[i][0]);
		}
		printf("\n\n");
		casos++;
	}


	return 0;
}

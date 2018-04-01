#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main(){

	int a,b,c,d;
	int casos = 1;
	while(scanf("%d%d%d%d",&a,&b,&c,&d)){

		if(a==0 && b==0 && c==0 && d==0) break;
		printf("Teste %d\n",casos);		

		int q,i,cont;
		cont = 0;
		scanf("%d",&q);
		for(i=0;i<q;i++){
			int x,y;
			scanf("%d %d",&x,&y);
			if(x<=c && x>=a && y<=b && y>=d) cont++;
		}
		printf("%d\n\n",cont);
		casos++;
	}

	return 0;
}

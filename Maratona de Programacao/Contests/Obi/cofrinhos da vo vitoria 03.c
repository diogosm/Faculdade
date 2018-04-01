#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


int main(){

FILE *in = stdin;
int n,i;
int instancia = 0;
int a1,a2;
int dif1,dif2;
dif1 = 0;
dif2 = 0;
int dinheiro[100][2];

fscanf(in,"%d",&n);

	while(n!=0){
		
		for(i=0;i<n;i++){
			fscanf(in, "%d %d",&dinheiro[i][0],&dinheiro[i][1]); 
			//dif1 = a1-a2;
			//printf("%d %d\n", dinheiro[i][0],dinheiro[i][1]);//if(dif1<0){
		}

		printf("Teste %d\n", instancia+1);
		dif1 = dinheiro[0][0] - dinheiro[0][1];
		printf("%d\n",dif1);
		for(i=1;i<n;i++){
			if(dif1<0){
				dif1 = (dinheiro[i][0]+dif1) - dinheiro[i][1];
			}
			else if(dif1>0){
				dif1 = dinheiro[i][0] - (dinheiro[i][1]-dif1);
			}
			else if(dif1==0){
				dif1 = dinheiro[i][0] - dinheiro[i][1];
			}
			printf("%d\n",dif1);
		}
		
		printf("\n");
		instancia++;
		fscanf(in, "%d", &n);
	}


return 0;
}



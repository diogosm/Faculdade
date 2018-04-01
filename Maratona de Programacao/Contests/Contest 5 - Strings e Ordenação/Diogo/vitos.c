#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int compare (const void * a, const void * b){
  return ( *(int*)a - *(int*)b );
}

int main(){
	
	int t,n,mediana,distancia,i;
	int vet[505];
	scanf("%d", &t);
	while(t!=0){
		distancia = 0;
		memset(vet, 0, sizeof(vet));
		scanf("%d", &n);
		for(i = 0;i<n;i++)
			scanf("%d",&vet[i]);

		qsort(vet, n, sizeof(int), compare);

		if(n %2 != 0){
			mediana = vet[n/2];		
		}else{
			mediana = vet[n/2]+vet[(n-1)/2];
			mediana /= 2;
		}

		for(i = 0;i<n;i++){
			distancia += fabs(vet[i]-mediana);
		}

		printf("%d\n", distancia);
		t--;
	}

	return 0;
}

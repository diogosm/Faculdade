#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<vector>
#include<set>
#include<valarray>
#include<cmath>
#include<algorithm>

using namespace std;

int main(){


	int n;
	int casos = 1;
	while(scanf("%d",&n) && n!=0){
		int vet[10000+1];
		for(int i = 0;i<n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			vet[i] = x-y;
		}
		int soma = 0;
		int best = -1;	
		int aux = 0;	
		int de,para;
		de = 1;
		para = 1;
		pair<int, int> since;
		for(int i=1;i<=n;i++){

			soma += vet[i-1];
			if(soma<0){ de=i+1; soma=0; }
			else{
				if(soma>0 && soma>=best){
					since = make_pair(de,i);
					best = soma;
				}
			}

		}
		de = since.first;
		para = since.second;
		if(best>0) printf("Teste %d\n%d %d\n\n",casos,de,para);
		if(best<=0) printf("Teste %d\nnenhum\n\n",casos);
		casos++;
	}

	return 0;
}

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

		int x,y;
		int u,v;
		x = v = -20000;
		u = y = 20000;		
		for(int i = 0;i<n;i++){
			int a,b,c,d;
			scanf("%d%d%d%d",&a,&b,&c,&d);
			if(a>x){
				x=a;			
			}
			if(c<u){
				u = c;
			}
			if(b<y){
				y = b;
			}
			if(d>v){
				v = d;
			}
		}
		//printf("%d %d %d %d\n",x,y,u,v);
		if( (x<u && y>v) ){
			printf("Teste %d\n%d %d %d %d\n\n",casos,x,y,u,v);
		}else{ printf("Teste %d\nnenhum\n\n",casos); }
		casos++;
	}


	return 0;
}

#include<math.h>
#include<stdlib.h>
#include<stdio.h>

int main(){

    int a,b,c,d;

	while(scanf("%d%d%d%d",&a,&b,&c,&d) && a!=0){

		if(a==c && b==d){ printf("0\n"); }
		else if( a==c || b==d || abs(c-a)==abs(d-b) ){
			printf("1\n");
		}else{ printf("2\n"); }

	}

    return 0;
}

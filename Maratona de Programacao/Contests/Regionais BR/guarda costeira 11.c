#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main(){

    double a,b,c;
    while(scanf("%lf%lf%lf",&a,&b,&c)!=EOF){

        double disX = sqrt( 12*12 + a*a );
        double t1,t2;
        t1 = 12.0/b;
        t2 = disX/c;
        if(t1<t2){
            printf("N\n");
        }else{
            printf("S\n");
        }
    }

    return 0;
}

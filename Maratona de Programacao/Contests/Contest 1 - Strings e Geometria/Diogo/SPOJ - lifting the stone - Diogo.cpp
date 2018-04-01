#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>

using namespace std;
int vet[1000000][2];

int main(){

    int T;
    int N;
    scanf("%d", &T);
    while(T!=0){
        scanf("%d", &N);
        int x1,y1;
        double cx,cy;
        double area;
        area = 0;
        cx = 0; cy = 0;
        scanf("%d %d",&x1,&y1);
        vet[0][0] = x1;
        vet[0][1] = y1;
        for(int i = 1; i<N; i++){
            scanf("%d %d", &vet[i][0], &vet[i][1]);
            area += (double)(x1*vet[i][1] - y1*vet[i][0]);
            //cout << area << " SHOW"<<endl;
            cx += ((double)(x1*vet[i][1] - y1*vet[i][0]))*((double)(vet[i][0]+x1));
            //cout << cx << " LOL " << x1 <<endl;
            cy += ( (double)(y1+vet[i][1]) ) *  (double)(x1*vet[i][1] - y1*vet[i][0]);
            x1 = vet[i][0];
            y1 = vet[i][1];
        }
        area += x1*vet[0][1] - y1*vet[0][0];
        cx += ((double)(x1*vet[0][1] - y1*vet[0][0]))*((double)(vet[0][0]+x1));
        cy += ((double)(x1*vet[0][1] - y1*vet[0][0]))*((double)(vet[0][1]+y1));

        printf("%.2lf %.2lf\n",cx/(3.0*area),cy/(3.0*area));

        T--;
    }

    return 0;
}

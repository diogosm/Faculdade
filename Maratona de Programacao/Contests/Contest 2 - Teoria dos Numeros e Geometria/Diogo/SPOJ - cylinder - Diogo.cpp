#include<iostream>
#include<math.h>
#include<vector>
#include<string>
#include<stdlib.h>
#include<stdio.h>
#include<algorithm>

using namespace std;

#define PI M_PI
const double pi = acos(-1);

int main(){

    double h,w;
    while(cin>>w>>h && (h!=0 && w!=0)){

        double maior, menor;
        maior = max(w,h);
        menor = min(w,h);
        double maxr = min(maior/2,menor);
        maxr /= 2;

        double r = menor/(2*PI);
        double h = maior - 2*r;
        if(r > maxr) r = maxr;      /** Raio nunca pode ser maior que "maior/2" **/
        double vol = PI*( (2*r)*((2*r)))*h;
        vol /= 4;

        double r1 = maior/(PI+1);
        r1 /= 2;
        double h1 = menor;
        if(r1 > maxr) r1 = maxr;
        double vol1 = PI*( (2*r1)*((2*r1)))*h1;
        vol1 /= 4;

        printf("%.3lf\n", max(vol, vol1));

    }

    return 0;
}

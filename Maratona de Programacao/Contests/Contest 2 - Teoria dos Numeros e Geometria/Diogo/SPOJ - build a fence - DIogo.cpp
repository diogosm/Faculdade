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

    double l;
    while(cin >> l && l!=0){
        double r = l/PI;
        double area = PI*(r*r);
        area /= 2;
        printf("%.2lf\n", area);
    }

    return 0;
}

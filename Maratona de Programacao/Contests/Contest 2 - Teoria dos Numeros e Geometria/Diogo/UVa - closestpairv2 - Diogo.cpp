#include<iostream>
#include<math.h>
#include<vector>
#include<string>
#include<stdlib.h>
#include<stdio.h>

/**
    Usando Divisao e conquista da AC! :)
**/

using namespace std;

#define INF 1000000

struct ponto{
    double x,y;
    ponto(double _x=0, double _y=0):x(_x),y(_y){}     //construtor
};

int n;
ponto vet[10005];

double distancia(double x1, double y1, double x2, double y2){
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

double min(double a, double b){
    if(a<b) return a;
    return b;
}

/** Problema de menor par de pontos - Algoritmo O(n log n) **/
double closest(int e, int d){

    if(e == d){
        return 1000000;
    }
    if(e == d-1){
        return distancia(vet[e].x,vet[e].y, vet[d].x, vet[d].y);
    }
    int meio = (e+d)/2;
    double res = min(closest(e,meio),closest(meio,d));
    //printf("SHOW %lf\n", res);
    /** Usa a a conquista para achar a menor distãncia **/
    for(int i = meio-1;i>=e && vet[meio].x-vet[i].x < res;i--){
        for(int j = meio+1;j<=d && vet[j].x-vet[meio].x < res;j++){
            double temp = distancia(vet[i].x, vet[i].y, vet[j].x, vet[j].y);
            if(temp < res){ res = temp; }
        }
    }
    return res;
}

int compare (const void * a, const void * b){
    ponto *x, *y;
    x = (ponto *)a; y = (ponto *)b;
    if(x->x!=y->x){
        if(x->x < y->x){
            return -1;
        }
        else{ return 1; }
    }
    else{
        if(x->y < y->y){
            return -1;
        }
        else{ return 1; }
    }
}

int main(){

    double x,y;
    while(cin>>n && n!=0){

        for(int i = 0;i<n;i++){
            cin >>x>>y;
            vet[i].x = x;
            vet[i].y = y;
        }
        qsort(vet, n, sizeof(ponto), compare);      /** ordena pela coord x **/
        //for(int i = 0;i<n;i++){
        //    cout << vet[i].x<<" "<<vet[i].y<<endl;
        //}
        /** Closest pair problem
            algoritmo baseado em = http://en.wikipedia.org/wiki/Closest_pair_of_points_problem
        **/
        double minDist = closest(0,n-1);
        if(minDist < 10000){ printf("%.4lf\n",minDist); }
        else{ printf("INFINITY\n"); }


    }

    return 0;
}

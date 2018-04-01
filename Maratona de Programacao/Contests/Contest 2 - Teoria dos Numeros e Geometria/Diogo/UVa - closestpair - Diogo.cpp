#include<iostream>
#include<math.h>
#include<time.h>
#include<vector>
#include<string>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

#define INF 10000

struct ponto{
    double x,y;
    ponto(double _x=0, double _y=0):x(_x),y(_y){}     //construtor
};

double distancia(double x1, double y1, double x2, double y2){
    return sqrt( (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) );
}

/** DA TLE =( **/

int main(){

    int n;
    double x,y;
    while(cin>>n && n!=0){

        vector<ponto> p;
        for(int i = 0;i<n;i++){
            cin >>x>>y;
            p.push_back(ponto(x,y));
        }
        /** Closest pair problem
            algoritmo baseado em = http://en.wikipedia.org/wiki/Closest_pair_of_points_problem
        **/
        double minDist = INF;
        vector<ponto>::iterator it;
        vector<ponto>::iterator it2;
        for( it = p.begin(); it != p.end() ; it++){
            for( it2 = p.begin(); it2 != p.end() ; it2++){
                if( (it != it2) && distancia((double)it->x,(double)it->y,(double)it2->x,(double)it2->y) < minDist ){
                    minDist = distancia((double)it->x,(double)it->y,(double)it2->x,(double)it2->y);
                }
            }
        }
        if(minDist == 10000){ printf("INFINITY\n"); }
        else printf("%.4lf\n", minDist);

    }

    return 0;
}

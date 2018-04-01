#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>

using namespace std;

struct triangulo{
    double la,lb,lc;
    double a1,a2,a3;
    triangulo(double x1,double x2,double x3, double y1,double y2,double y3){
        la = sqrt( (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) ); //lado AB
        lb = sqrt( (x3-x1)*(x3-x1) + (y3-y1)*(y3-y1) ); //lado AC
        lc = sqrt( (x3-x2)*(x3-x2) + (y3-y2)*(y3-y2) ); //lado BC
    }
};

//const double pi = acos(-1);
const double pi = 2*acos(0.0);

int main(){
    double x1,x2,x3,y1,y2,y3;
    while(cin>>x1>>y1>>x2>>y2>>x3>>y3){
        triangulo t(x1,x2,x3,y1,y2,y3);
        int ladosIguais = 0;
        //int x = 0;
        //printf("lados %lf %lf %lf\n", t.la, t.lb, t.lc);

        //if( (t.la >= t.lb + t.lc) || (t.lb >= t.la + t.lc) || (t.lc >= t.la + t.lb) ){
        if( fabs((x1-x2)*(y1-y3) - (y1-y2)*(x1-x3)) < 1e-7 ){
            printf("Not a Triangle\n");
        }
        else{
            /** Calcula os lados iguais do triangulo **/
            cout<<t.lc<<endl;
            t.lc = 5.38994;
            cout << fabs(t.lc-t.la) << endl;
            if(fabs(t.lb-t.la)<= 0.01 && fabs(t.lb-t.la)>=-0.01){   ladosIguais++;  }
            if(fabs(t.lc-t.la)<= 0.01 && fabs(t.lc-t.la)>=-0.01){ cout << fabs(t.lc-t.la) << endl;  ladosIguais++; }
            if(fabs(t.lb-t.lc)<= 0.01 && fabs(t.lb-t.lc)>=-0.01){   ladosIguais++; }
            if(ladosIguais == 0) printf("Scalene ");
            if(ladosIguais == 1) printf("Isosceles ");
            if(ladosIguais > 1){ printf("Equilateral "); }

            double a1,a2,a3;
            int aa,ab,ac;
            a1 = acos( ((t.la*t.la)+(t.lb*t.lb)-(t.lc*t.lc))/(2*t.la*t.lb) );   //calcula o angulo
            a1 = a1*(180/pi);   aa = (int)a1;                                                   //converte de radianos pra grau
            a2 = acos(((t.la*t.la)+(t.lc*t.lc)-(t.lb*t.lb)) / (2*t.la*t.lc)) ;
            a2 = a2*(180/pi);   ab = (int)a2;
            a3 = acos(((t.lb*t.lb)+(t.lc*t.lc)-(t.la*t.la)) / (2*t.lb*t.lc));
            a3 = a3*(180/pi);   ac = (int)a3;
            //printf("SHOW %lf %lf %lf   ",a1,a2,a3);
            if( (aa<=92 && aa>=88) || (ab<=92 && ab>=88) || (ac<=92 && ac>=88) ){
                printf("Right\n");
            }else if(a1>90 || a2 > 90 || a3 > 90){
                printf("Obtuse\n");
            }else{ printf("Acute\n"); }
        }
    }
    printf("End of Output\n");
    return 0;
}

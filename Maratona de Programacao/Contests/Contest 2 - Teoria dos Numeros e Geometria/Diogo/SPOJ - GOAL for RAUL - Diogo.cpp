#include<stdio.h>
#include<map>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<queue>
#include<stack>
#include<cmath>

#define PI acos(-1)

struct ponto{
    double x,y;
    double raio;
    ponto(double _x=0, double _y=0, double _raio=0):x(_x),y(_y),raio(_raio){}     //construtor
    ponto operator-(ponto p){ return ponto(x-p.x,y-p.y);}   //define operacao de menos
	double operator*(ponto p){ return (x*p.y)-(y*p.x);}        //---//---  de multiplicacao
};

using namespace std;

int main(){
    
    int t;
    scanf("%d", &t);
    while(t!=0){
          ponto goleiro;
          ponto bola;
          double x,y,r;
          r = 0;
          scanf("%lf %lf", &x,&y);
          bola.x = x;
          bola.y = y;
          
          scanf("%lf %lf %lf", &x,&y,&r);
          goleiro.x = x;
          goleiro.y = y;
          goleiro.raio = r;
          
          /** Elementos da equacao da reta pra primeira trave (Ax + By + C = 0) **/
          /**
             Coordenadas do gol = 52,5 , 3,66
                                  52,5 , -3,66
          **/
          double A,B,C;
          A = bola.y - 3.66;
          B = 52.5 - bola.x;
          C = (bola.x*3.66) - (52.5*bola.y);
          
          double distancia = (A*goleiro.x + B*goleiro.y + C)*(A*goleiro.x + B*goleiro.y + C);
          distancia = sqrt(distancia);
          distancia = distancia/sqrt( (A*A) + (B*B) );
          
          /** Segunda trave **/
          double A1,B1,C1;
          A1 = bola.y - (-3.66);
          B1 = (52.5) - bola.x;
          C1 = (bola.x*(-3.66)) - (52.5*bola.y);
          
          double distancia1 = (A1*goleiro.x + B1*goleiro.y + C1)*(A1*goleiro.x + B1*goleiro.y + C1);
          distancia1 = sqrt(distancia1);
          distancia1 = distancia1/sqrt( (A1*A1) + (B1*B1) );
          
          if(distancia > goleiro.raio || distancia1 > goleiro.raio){
                 printf("Goal!\n");
          }else{ printf("No goal...\n"); }

          t--;            
    }    
    
}

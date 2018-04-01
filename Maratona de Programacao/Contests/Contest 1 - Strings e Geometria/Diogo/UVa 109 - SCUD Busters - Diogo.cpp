#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<vector>

#define INF 1<<25
using namespace std;

struct ponto{
    int x,y;
    ponto(int _x=0, int _y=0):x(_x),y(_y){}     //construtor
    ponto operator-(ponto p){ return ponto(x-p.x,y-p.y);}   //define operacao de menos
	int operator*(ponto p){ return (x*p.y)-(y*p.x);}        //---//---  de multiplicacao
};

struct pais{
    //ponto p[101];
    vector<ponto> pontos;
    int pontosConvexHullN;
    double area;
    int destruido;
} paises[100];

/** Variáveis globais **/
const double pi = acos(-1);
//const double pi = 2*acos(0.0);
int nPaises;
int N;

double ccw(ponto p1, ponto p2, ponto p3){
    return (p2.x-p1.x)*(p3.y-p1.y) - (p2.y-p1.y)*(p3.x-p1.x);
}

bool funcao(ponto a, ponto b){
    return (((a-paises[nPaises].pontos[0])*(b-paises[nPaises].pontos[0])) > 0);
}

void graham_scan(){
    /** baseado = http://en.wikipedia.org/wiki/Graham_scan **/
    int menorY = INF;
    int x = INF;
    int k;
    /** encontra menor coordenada y **/
    for(int i = 0; i<N; i++){
        if( paises[nPaises].pontos[i].y < menorY || (paises[nPaises].pontos[i].y == menorY && paises[nPaises].pontos[i].x < x) ){
            menorY = paises[nPaises].pontos[i].y;
            x = paises[nPaises].pontos[i].x;
            k = i;
        }
    }
    // troca vet[0] com vet[menor coordenada y]
    swap(paises[nPaises].pontos[0], paises[nPaises].pontos[k]);
    // ordena pelo angulo polar
    sort(paises[nPaises].pontos.begin()+1, paises[nPaises].pontos.end(), funcao);
    int M = 1;
    /** Calcula todos os pontos para addd no convex hull **/
    for(int i = 2;i<N;i++){
        while( M>1 && ccw(paises[nPaises].pontos[M-1],paises[nPaises].pontos[M],paises[nPaises].pontos[i]) <= 0 ){
            M -= 1;
            //if(M>1){ M--; }
            //else if(i==N){ break; }
            //else{ i++; }
        }
        M++;
        swap(paises[nPaises].pontos[M],paises[nPaises].pontos[i]);
    }
    //printf("M = %d\n", M);
    //for(int i = 0; i<=M;i++){
        //printf("%d %d\n", paises[nPaises].pontos[i].x, paises[nPaises].pontos[i].y);
    //}
    paises[nPaises].pontosConvexHullN = M+1;
    paises[nPaises].destruido = 0;

    M++;    /** normatiza o tamanho do convex hull pra calcular a area **/
    for(int i = 0; i <M; ++i)       //calc a area do poly
		paises[nPaises].area += paises[nPaises].pontos[i] * paises[nPaises].pontos[(i+1)%M];
	if(paises[nPaises].area < 0) paises[nPaises].area = -paises[nPaises].area;
	//printf("AREA = %lf \n", paises[nPaises].area);
}

/** ponto dentro do poligono **/
/** Disponivel em : http://www.ecse.rpi.edu/Homepages/wrf/Research/Short_Notes/pnpoly.html **/
int pnpoly(int testx, int testy, pais p){
  int i, j, c = 0;
  for (i = 0, j = p.pontosConvexHullN-1; i < p.pontosConvexHullN; j = i++) {
    if ( ((p.pontos[i].y>testy) != (p.pontos[j].y>testy)) &&
	 (testx < (p.pontos[j].x-p.pontos[i].x) * (testy-p.pontos[i].y) / (p.pontos[j].y-p.pontos[i].y) + p.pontos[i].x) )
       c = !c;
  }
  return c;
}

int main(){

    int x,y;

    for( nPaises = 0 ; scanf("%d", &N) && N != -1 ; nPaises++ ){
        for(int i = 0; i< N ; i++ ){
            scanf("%d%d", &x,&y);
            paises[nPaises].pontos.push_back(ponto(x,y));
        }
        graham_scan();
    }

    double areaDestruida = 0.0;
    while(scanf("%d%d",&x,&y) == 2){
        for(int i = 0;i<nPaises;i++){
            if(pnpoly(x,y,paises[i]) == 1 && paises[i].destruido == 0){
                paises[i].destruido = 1;
                areaDestruida += paises[i].area;
            }
        }
    }
    printf("%.2lf\n", areaDestruida/2);

    return 0;
}

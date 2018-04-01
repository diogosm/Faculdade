#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

using namespace std;

typedef struct ponto{
	double x,y;
} Ponto;

typedef struct circulo{
	double x,y;
	double raio;
} Circulo;

Circulo circulo;
Ponto pontos[1000000];
Ponto boundary[1000000];

int estahNoCirculo(Circulo local, double x, double y){
	return ( (local.x-x)*(local.x-x) + (local.y-y)*(local.y-y) <= (local.raio*local.raio) );
}

Circulo calcCirculo2(int ab, int ap){
	
	Circulo aux;
	double p1x = boundary[ab].x;
	double p1y = boundary[ab].y;
	double p2x = pontos[ap].x;
	double p2y = pontos[ap].y;

	double cx = 0.5*(p1x+p2x);
	double cy = 0.5*(p1y+p2y);
	double raio = sqrt( (p1x-cx)*(p1x-cx) + (p1y-cy)*(p1y-cy) );

	aux.x = cx;
	aux.y = cy;
	aux.raio = raio;

	return aux;
}

Circulo calcCirculo2Boundary(int ab, int ap){
	
	Circulo aux;
	double p1x = boundary[ab].x;
	double p1y = boundary[ab].y;
	double p2x = boundary[ap].x;
	double p2y = boundary[ap].y;

	double cx = 0.5*(p1x+p2x);
	double cy = 0.5*(p1y+p2y);
	double raio = sqrt( (p1x-cx)*(p1x-cx) + (p1y-cy)*(p1y-cy) );

	aux.x = cx;
	aux.y = cy;
	aux.raio = raio;

	return aux;
}

Circulo calcCirculo3(int a1, int a2, int a3){

	Circulo aux;
	double p1x = boundary[a1].x;
	double p1y = boundary[a1].y;
	double p2x = boundary[a2].x;
	double p2y = boundary[a2].y;
	double p3x = boundary[a3].x;
	double p3y = boundary[a3].y;

        double a = p2x - p1x;
        double b = p2y - p1y;     
        double c = p3x - p1x;
        double d = p3y - p1y;
        double e = a * (p2x + p1x) * 0.5 + b * (p2y + p1y) * 0.5;
        double f = c * (p3x + p1x) * 0.5 + d * (p3y + p1y) * 0.5;
        double det = a*d - b*c;    

        double cx = (d*e - b*f)/det;
        double cy = (-c*e + a*f)/det;
	double raio = sqrt( (p1x-cx)*(p1x-cx) + (p1y-cy)*(p1y-cy) );

	aux.x = cx;
	aux.y = cy;
	aux.raio = raio;

	return aux;
	
}

Circulo mec(int n, int b){

	Circulo local;

	if (b == 3) 
        {	local = calcCirculo3(0,1,2);  
        } else if (n == 1 && b == 0)			//caso inicial
        {	local.x = pontos[0].x;
		local.y = pontos[0].y;
		local.raio = 0;    
        } else if (n == 0 && b == 2)
        {	local = calcCirculo2Boundary(0,1);    
        } else if (n == 1 && b == 1)
        {	local = calcCirculo2(0,0);   
        } else 
	{
		local = mec(n-1, b);
		//printf("local.x = %f e local.y = %f e n=%d", local.x, local.y, n);
		if( !(estahNoCirculo(local, pontos[n-1].x, pontos[n-1].y)) ){
			boundary[b].x = pontos[n-1].x;
			boundary[b].y = pontos[n-1].y;
			b++;
			local = mec(n-1, b);
		}
	} 
	
	return local;
}

void calcMec(int n){
	Circulo aux = mec(n, 0);
	printf("%.2lf\n%.2f %.2f\n", aux.raio,aux.x, aux.y);
}

int main(){

	int c,n,i;
	scanf("%d", &c);
	while(c!=0){
		memset(pontos,0,sizeof(pontos));
		memset(boundary,0,sizeof(boundary));
		scanf("%d", &n);
		for(i=0;i<n;i++){
			scanf("%lf %lf", &pontos[i].x, &pontos[i].y);
		}
		calcMec(n);
		c--;
	}


	return 0;
}


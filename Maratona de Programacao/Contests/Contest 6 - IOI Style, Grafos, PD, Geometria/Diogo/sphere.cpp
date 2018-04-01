#include<vector>
#include<string>
#include<stdlib.h>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<math.h>
using namespace std;

/**
   Baseado em: http://saketachyon.wordpress.com/2009/11/14/radius-of-a-sphere-inscribed-in-a-general-tetrahedron/
**/

//http://www.had2know.com/academics/tetrahedron-volume-6-edges.html
double area(int x,  int y, int z){
	double sum = (double)(2*x*x*y*y + 2*x*x*z*z + 2*z*z*y*y - x*x*x*x - y*y*y*y - z*z*z*z);
	sum = sqrt(sum);
	sum = sum/4.0;
	return sum;
}		//Usando essa fórmula dá erro de precisao :(

/** Usando a fórmula de Heron **/
double area1(int x, int y, int z){
	double s = (x+y+z);
	s /= 2;
	double T = s*(s-x)*(s-y)*(s-z);
	T = sqrt(T);
	return T;
}

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i<t;i++){
		vector<int> tetra;
		double A,B,C,D,E,F;
		for(int j = 0; j<6; j++){
			int x;
			scanf("%d", &x);
			tetra.push_back(x);
		}
		A = tetra[0]*tetra[0];
		B = tetra[1]*tetra[1];
		C = tetra[2]*tetra[2];
		D = tetra[3]*tetra[3];
		E = tetra[4]*tetra[4];
		F = tetra[5]*tetra[5];
		double volume = - (A*B*D) - (A*C*E) - (B*C*F) - (D*E*F) + (A*C*D) + (B*C*D) + (A*B*E) + (B*C*E)
           			+ (B*D*E) + (D*C*E) + (A*B*F) + (A*C*F) + (A*D*F) + (F*C*D) + (A*F*E) + (F*B*E)
           			- (C*C*D) - (C*D*D) - (B*B*E) - (B*E*E) - (A*F*A) - (A*F*F);
		volume /= 144;
		volume = sqrt(volume);
		/** Calcula a área da superfície para cada face triangular **/
		double S = area1(tetra[5], tetra[1], tetra[2]) + area1(tetra[0], tetra[4], tetra[2])
			   + area1(tetra[5], tetra[3], tetra[4]) + area1(tetra[1], tetra[0], tetra[3]);
		double r = (volume*3.0)/S;
		printf("%.4lf\n", r);
		tetra.clear();
	}

	return 0;
}


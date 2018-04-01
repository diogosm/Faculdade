#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


int main(){

int n,a,b,soma;
char nome1[11];
char nome2[11];
int instancia = 1;

FILE *in = stdin;

fscanf(in, "%d", &n);
fscanf(in, "%s", nome1);
fscanf(in, "%s", nome2);

while(n!=0){

	printf("Teste %d\n", instancia);

	while(n!=0){
		fscanf(in, "%d %d", &a, &b);
		soma = a+b;

		if(soma%2==0){ printf("%s\n",nome1); }
		else{ printf("%s\n", nome2); }
		n--;
	}
	printf("\n");
	instancia++;
	fscanf(in, "%d", &n);
	fscanf(in, "%s", nome1);
	fscanf(in, "%s", nome2); 
}


return 0;
}



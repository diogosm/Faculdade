#include<math.h>
#include<stdlib.h>
#include<stdio.h>
#include<iostream>

using namespace std;

/**
    Usando Divisão e Conquista
    http://www.hkoi.org/training2011/files/Recursion_Divide_and_Conquer.pdf
    http://webdocs.cs.ualberta.ca/~mreza/courses/204-F07/lec-notes/week07.pdf
**/
int bigmod(int b, int p, int m){
   int a;
   if (p == 0)
      return 1;
   if (p%2 == 0){
      a = bigmod(b,p/2,m);
      return (a*a) % m;
   }else{
      return ((b % m) * bigmod(b,p-1,m)) % m;
   }
}

int main(){

    int B,P,M;
    while(cin>>B>>P>>M){

        cout<<bigmod(B,P,M)<<endl;

    }

    return 0;
}

#include<iostream>
#include<math.h>
#include<vector>
#include<string>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

int main(){

    int n;
    int t = 1;
    while(cin>>n && n>0){

        printf("Case %d: %d\n", t++,(int)ceil((log2((double)n))));

    }
    return 0;
}

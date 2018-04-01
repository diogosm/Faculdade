#include<stdio.h>
#include<map>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<sstream>

using namespace std;

int main(){
    
    string frase;
    string a,b;
    map<string,string> m;
    while(getline(cin, frase) && frase.size()!=0){
          stringstream x;           //ler a frase da linha toda e separa usando stringstream
          x << frase;
          x >> a>>b;
          m[b] = a;
          //cout<<m[b]<<endl;
    }
    
    while(cin>>frase){
          if(m.count(frase) > 0){
                cout<<m[frase]<<endl;
          }else{
                printf("eh\n");
          }
    }
    
    
    return 0;
}

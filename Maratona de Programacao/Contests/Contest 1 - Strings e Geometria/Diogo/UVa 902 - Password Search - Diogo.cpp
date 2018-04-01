#include<iostream>
#include<map>

using namespace std;
int N;
int Max;
string palavra;
string resul;

int main(){

    while(cin >> N){
        Max = -1;
        cin >> palavra;
        map<string,int> mapa;
        map<string,int>::iterator i;
        int tamanho = palavra.length();
        for(int i = 0; i<=tamanho - N; i++){
            mapa[palavra.substr(i,N)]++;
        }
        i = mapa.begin();
        Max = i->second;
        for (  ; i != mapa.end(); i++ ){
            if(i->second > Max){ resul = i->first; Max = i->second; }
        }
        cout<<resul<<endl;
    }

    return 0;
}

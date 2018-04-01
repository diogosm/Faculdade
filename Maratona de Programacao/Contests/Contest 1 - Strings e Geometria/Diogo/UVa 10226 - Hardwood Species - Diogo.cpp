#include<stdio.h>
#include<map>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>

using namespace std;

int main(){

    int T; scanf("%d", &T);
    string espaco;
    int total;
    getline(cin, espaco);
    getline(cin, espaco);
    bool prim = true;

    while(T!=0){
        total = 0;
        if(!prim) puts("");
        map<string, int> m;
        map<string, int>::iterator it;
        for (string s; getline(cin, s) && s != "";){
            m[s]++; total++;
        }     /** ler a entrada e joga na map **/
        for( it = m.begin() ; it != m.end(); it++ ){
            cout << it->first;
            printf(" %.4lf\n", (double)((double)(it->second*100)/((double)total)));
        }
        prim = false;

        T--;
    }


    return 0;
}

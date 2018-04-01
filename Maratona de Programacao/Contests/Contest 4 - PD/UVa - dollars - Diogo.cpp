#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <utility>
#include <set>
#include <math.h>
#include <cstdio>
#include <iostream>
#include <bitset>
#include <cstring>
#include <list>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <numeric>
#include <functional>
#include <iterator>
#include <sstream>
#include <stack>
#include <ext/numeric>
typedef long long int llint;
typedef unsigned int uint;
#define hash_map unordered_map
#define hash_set unordered_set
#include<iostream>
#include<math.h>
#include<vector>
#include<string>
#include<stdlib.h>
#include<stdio.h>
#include<algorithm>
#include<string.h>

using namespace std;


int main(){
    /**
        http://www.ime.usp.br/~pf/analise_de_algoritmos/aulas/mochila-subsetsum.html
    **/

    int candidates[11] = {1, 2, 4, 10, 20, 40, 100, 200, 400, 1000, 2000};

    unsigned long long int preVet[6009];
    memset(preVet,0,sizeof(preVet))
    preVet[0] = 1;
    for(int i = 0; i<11;i++){
        for(int j = 1; j<6001; j++){
            if( j>= candidates[i] ){
                preVet[j] += preVet[j-candidates[i]];
            }
        }
    }

    //for(int i = 0; i<6000; i++){
    //    cout<<preVet[i]<<" ";
    //}
    double c;
    while(cin>>c && c!= 0.0){
        unsigned long long int k = c*20;
        cout.setf(ios::fixed,ios::floatfield);
        cout.precision(2);
        cout.width(6);
        cout<<c;
        cout.width(17);
        cout<<preVet[k]<<endl;
    }
}

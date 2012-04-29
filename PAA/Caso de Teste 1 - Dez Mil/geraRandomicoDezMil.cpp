/** Trabalho 1 de PAA
    @author = Diogo Soares Moreira
    @date = 29/04/2012
**/

#include <cctype>
#include <map>
#include <utility>
#include <set>
#include <cstdio>
#include <bitset>
#include <cstring>
#include <list>
#include <cmath>
#include <set>
#include <queue>
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
#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <time.h>
#include <ctime>

using namespace std;

int main(){

    clock_t beg;
    beg=clock();
    srand(time(NULL));

    for(int j = 0; j<50; j++){
        for(int i = 0; i<10000 ;i++){       //gerando nums aleatório até 10^4 casas (short int)
            unsigned short int numero = (unsigned short int)RAND_MAX*rand();
            cout<<numero<<" ";
        }
        cout<<endl;
    }

    //printf("tempo de execucao:%d\n",clock()-beg);
    return 0;
}

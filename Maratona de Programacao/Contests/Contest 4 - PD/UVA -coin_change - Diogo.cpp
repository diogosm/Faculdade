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
using namespace std;


int main(){

    int candidates[5] = {1,5,10,25,50};
    unsigned long long int preVet[800000] = { 0 };
    preVet[0] = 1;
    for(int i = 0; i<5;i++){
        for(int j = 1; j<800001; j++){
            if( j>= candidates[i] ){
                preVet[j] += preVet[j-candidates[i]];
            }
        }
    }
    int n;
    //scanf("%d", &n);
    //printf("%lld\n", preVet[n]);

    while(cin>>n){

	printf("%lld\n", preVet[n]);
    }

    return 0;
}

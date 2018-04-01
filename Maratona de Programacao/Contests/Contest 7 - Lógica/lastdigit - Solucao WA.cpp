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
using namespace std;
using namespace __gnu_cxx;
typedef pair<int,int> pii;
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

#define unsigned long long int llint;

llint powmodn(llint a, llint b, llint c) {
    llint x = 1, y = a;
    while (b > 0) {
        if ((b & 1) == 1)
            x = (x * y) % c;
        y = (y * y) % c;
        b >>= 1;
    }
    return x % c;
}

int main(){

	int n;
	scanf("%d",&n);
	for( ; n>0 ; --n){
		llint a,b;
		scanf("%lld %lld",&a,&b);
		llint res = powmodn(a,b,10);
		printf("%lld\n",res);
	}

	return 0;
}

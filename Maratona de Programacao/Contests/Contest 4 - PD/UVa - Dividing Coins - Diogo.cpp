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

#include <ctime>
#define FOR(i,a,b) for(int i = (int)a; i<(int)b; i++)
#define INF 50001

int coins[1000];
int soma;
int dp[101][50001];

int compare(const void * a, const void * b){
    return ( *(int*)a - *(int*)b);
}

int main(){

    int T,n;
    clock_t beg;
    beg=clock();
    scanf("%d", &T);

    while(T!=0){
        scanf("%d", &n);
        soma = 0;
        memset(coins, 0, sizeof(coins));
        FOR(i,0,n){
            scanf("%d", &coins[i]);
            soma += coins[i];
        }
        qsort(coins, n, sizeof(int), compare);

        memset(dp, 0, sizeof(dp));
        FOR(i,1,n+1){
            FOR(somas, 1,soma+1){
                dp[i][somas] = dp[i-1][somas];
                if( somas >= coins[i-1]){
                    //dp[i][somas] = max( dp[i-1][somas] , dp[i-1][somas-coins[i]] + coins[i-1] );
                    dp[i][somas] = max( dp[i-1][somas] , dp[i-1][somas-coins[i-1]] + coins[i-1] );
                }
            }
        }

        /**
            Baseado em:
            http://en.wikipedia.org/wiki/Knapsack_problem
            http://www.personal.kent.edu/~rmuhamma/Algorithms/MyAlgorithms/Dynamic/knapsackdyn.htm
        **/

        int result = INF;
        FOR(i,0,soma+1){
            result = min( result , (int)fabs( soma-dp[n][i]-dp[n][i] ));
            //cout<<result<<" ";
        }
        cout<<result<<endl;

        /**for(int i = 0; i<n+1;i++){
            for(int j = 0; j<soma+1; j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }**/
        T--;
    }
    //printf("tempo de execucao:%d\n",clock()-beg);
    return 0;
}

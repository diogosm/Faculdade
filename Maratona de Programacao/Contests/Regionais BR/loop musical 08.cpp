#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){

    int n;
    while(scanf("%d",&n) && n!=0){
        vector<int> v;
        for(int i = 0;i<n;i++){
            int x;
            scanf("%d",&x);
            v.push_back(x);
        }

        int res = 0;

        if( (v[n-1]>v[0] && v[1]>v[0]) || (v[n-1]<v[0] && v[1]<v[0]) ) res++;
        if( (v[n-2]>v[n-1] && v[0]>v[n-1]) || (v[n-2]<v[n-1] && v[0]<v[n-1]) ) res++;

        for(int i = 1;i<n-1;i++){
            if( (v[i-1]<v[i] && v[i]>v[i+1]) || (v[i-1]>v[i] && v[i]<v[i+1]) ) res++;
        }
        cout<<res<<endl;
        v.clear();
    }

    return 0;
}

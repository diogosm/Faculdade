#include<stdio.h>
#include<map>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<queue>
#include<stack>
#include<time.h>

using namespace std;

map<String,int> keywords;

int main(){

    string k;
    while(cin>>k && k!="::"){
        keywords[k]++;
    }




    return 0;
}

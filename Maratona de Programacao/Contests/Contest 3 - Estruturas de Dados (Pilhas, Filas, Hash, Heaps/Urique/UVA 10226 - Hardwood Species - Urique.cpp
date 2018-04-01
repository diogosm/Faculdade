#include <stdio.h>
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <string>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <map>

using namespace std;


int main()
{
int numTest;
cin >> numTest;
string str;
getline(cin, str);
getline(cin, str);
for(int i = 0 ; i < numTest ; i++ ){
    string wood;
    map<string,int> trees;
    map<string,int>:: iterator it;

    int cont = 0;
    while(getline (cin,wood)){
        if(wood != ""){
        trees[wood]++;
        cont++;
        }
        else break;
    }

    for(it = trees.begin(); it != trees.end() ; it++){
       cout << it->first << " ";
       printf("%.4f\n",(double)((double)(it->second*100)/((double)cont)));
    }
    if(i+1 < numTest){
        puts("");
    }

}

return 0;
}

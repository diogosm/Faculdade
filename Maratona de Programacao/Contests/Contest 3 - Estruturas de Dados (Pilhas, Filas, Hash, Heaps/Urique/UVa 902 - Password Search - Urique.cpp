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


int numX = 0;
int n;
string str;
string sub;
while (cin >> n){
    cin >> str;
    map<string,int> chave;
    map<string,int>:: iterator it;
    for (int i = 0; i <str.size()-n+1; i++ ){
        sub = str.substr(i,n);
        chave[sub]++;

    }
sub.clear();
numX = -1;
    for(it = chave.begin() ; it != chave.end(); it++){
        if(numX < it->second){
            numX = it->second;
            sub = it->first;
        }

    }
cout << sub << endl;
}

return 0;
}

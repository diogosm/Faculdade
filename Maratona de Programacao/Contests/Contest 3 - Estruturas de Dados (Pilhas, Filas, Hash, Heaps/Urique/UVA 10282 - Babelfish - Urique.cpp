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
string str;
string sub1,sub2;
map<string,string> words;
map<string,string>:: iterator it;
while(getline(cin,str)){
    int esp = -1;
    esp = str.find(" ");

    if(esp != -1){ // eh a definicao do dicionario
        words[str.substr(esp+1,str.size())] = str.substr(0,esp);
    }
    else {
        if(str != ""){ // palavras a serem decifradas
            it = words.find(str);
            if(it != words.end())
            cout << it->second << endl;
            else
            cout << "eh" << endl;
        }
    }


}


return 0;
}

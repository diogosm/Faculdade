#include<stdlib.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<string.h>
#include<stdio.h>

using namespace std;
string line;

bool comp(string a , string b){
    string s1 = a+b,s2 = b+a;
    return s1 < s2;
}

int main(){

	int n;
	string s = "";
	string k;
	while(cin>>n){

		vector <string> v(n,"");
		for(int i=0;i<=n;i++)
			cin>>v[i];

		sort(v.begin(),v.end(),comp);
		for(int i=0;i<v.size();i++)
			s += v[i];

		cout<<s<<endl;

	}

	return 0;
}

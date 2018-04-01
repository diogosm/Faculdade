#include<stdio.h>
#include<string>
#include<stdlib.h>
#include<math.h>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>

using namespace std;

map<char,int> m;

int maior(char a, char b){
	if(m[a]>m[b]){
		return 1;
	}else if(m[a]<m[b]){
		return 2;
	}
	return 0;
}

int main(){

	m['0'] = 0;	m['1'] = 1;	m['2'] = 2;	m['3'] = 3;	m['4'] = 4;	m['5'] = 5;	m['6'] = 6;	m['7'] = 7;
	m['8'] = 8;	m['9'] = 9;	m['A'] = 10; m['B'] = 11; m['C'] = 12; m['D'] = 13; m['E'] = 14; m['F'] = 15;
	m['G'] = 16;

	while(1){
		string a,b;
		int t1,t2;
		cin>>a>>b;
		
		if(a=="*" && b=="*") break;
		
		t1 = a.size();
		t2 = b.size();
		if(t1>t2){
			int d = t1-t2;
			string aux="0";
			for(int i =0;i<d;++i){
				b = aux+b;
			}
		}else if(t2>t1){
			int d = t2-t1;
			string aux="0";
			for(int i =0;i<d;++i){
				a = aux+a;
			}
		}
		//cout<<a<<" "<<b<<endl;
		
		int greater = 0;
		for(int i = 0;i<b.size();++i){
			if(maior(a[i],b[i])==1){ greater = 1; break; }
			else if(maior(a[i],b[i])==2){ greater = 2; break; }
		}
		if(greater == 2){ printf("<\n"); }
		else if(greater == 1){ printf(">\n"); }
		else{ printf("=\n"); }
		
	}

	return 0;
}

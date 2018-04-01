#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<math.h>
#include<cmath>

using namespace std;

int main(){

	int n;
	scanf("%d",&n);
	for( ; n>0;--n){
		int place;
		scanf("%d",&place);
		if(place == 1){
			printf("poor conductor\n");
		}else{
			char dir;
			char pos;
			int row;
			
			if(place%10 == 2 || place%10 == 1){
				dir = 'L';
				pos = 'W';
			}else if(place%10 == 3 || place%10 == 0){
				dir = 'L';
				pos = 'A';
			}else if(place%10 == 4 || place%10 == 9){
				dir = 'R';
				pos = 'A';
			}else if(place%10 == 5 || place%10 == 8){
				dir = 'R';
				pos = 'M';
			}else if(place%10 == 6 || place%10 == 7){
				dir = 'R';
				pos = 'W';
			}
		
			if(place%10 == 1 || place%10 == 6){ place--; }
			else if(place%10 == 2 || place%10 == 7){ place=place+3; }
			else if(place%10 == 3 || place%10 == 8){ place=place+2; }
			else if(place%10 == 4 || place%10 == 9){ place++; }
			else if(place%10 == 5 || place%10 == 0){ /*nothing*/ }
			row = place/5;
			
			printf("%d %c %c\n",row, pos, dir);
			
		}
	}

	return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){

    int k;
    while(scanf("%d",&k) && k!= 0){

        int xdiv,ydiv;
        scanf("%d %d",&xdiv, &ydiv);

        for(int i = 0;i<k;i++){
            int x,y;
            scanf("%d %d",&x,&y);
            if(x == xdiv || y == ydiv){
                printf("divisa\n");
            }
            else if(x>xdiv && y>ydiv){ printf("NE\n"); }
            else if(x<xdiv && y<ydiv){ printf("SO\n"); }
            else if(x>xdiv && y<ydiv){ printf("SE\n"); }
            else if(x<xdiv && y>ydiv){ printf("NO\n"); }
        }

    }

    return 0;
}

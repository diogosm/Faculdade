#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>

using namespace std;

int main(){


    int n;
    while(scanf("%d",&n)!=EOF){
        int vet[61][2],i,a;
        char c;
        memset(vet,0,sizeof(vet));
        for(i=0;i<n;i++){
            scanf("%d %c",&a,&c);
            if(c == 'D'){
                vet[a][0]++;
            }else{
                vet[a][1]++;
            }
        }
        int max = 0;
        for(i=30;i<=60;i++){
            int aux =  min(vet[i][0],vet[i][1]);
            max += aux;
        }
        printf("%d\n",max);
    }

    return 0;
}

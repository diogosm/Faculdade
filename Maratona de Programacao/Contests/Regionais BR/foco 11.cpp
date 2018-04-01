#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<vector>

using namespace std;

typedef struct{
    int a,b;
} foco;

int compare (const void * a, const void * b)
{
  if( (*(foco*)a).a < (*(foco*)b).a ){ return -1; }
  else if( (*(foco*)a).a > (*(foco*)b).a ){ return 1; }
  else{
    if( (*(foco*)a).b < (*(foco*)b).b ){ return -1; }
    else if( (*(foco*)a).b > (*(foco*)b).b ){ return 1; }
    else{ return 0; }
  }
}

int main(){

    int n;
    while(scanf("%d",&n)!=EOF){
        foco focos[n];
        for(int i = 0;i<n;i++){
            scanf("%d %d", &(focos[i].a),&(focos[i].b));
        }

        qsort(focos,n,sizeof(foco),compare);

        //for(int i =0;i<n;i++)
            //printf("%d %d\n",focos[i].a,focos[i].b);

        int ini,last,qtd;
        qtd = 0;
        ini = focos[0].a; last = focos[0].b;
        for(int i =1;i<n;i++){
            if(focos[i].a<=last){
                last = min(last,focos[i].b);
            }
            else{
                qtd++;
                ini = focos[i].a;
                last = focos[i].b;
            }
        }
        printf("%d\n",++qtd);
    }
    return 0;
}

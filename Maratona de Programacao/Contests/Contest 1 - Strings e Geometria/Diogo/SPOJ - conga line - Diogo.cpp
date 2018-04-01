#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

long long int vet[1000000];

int main(){
    long long int N,i,mid,atual,walk;
    while(1){
        scanf("%lld",&N);

        if(N==0) break;
        else if(N==1){ scanf("%lld", &vet[0]); printf("0\n"); }
        else{
            for(i=0;i<N;i++)
                scanf("%lld", &vet[i]);

            walk = 0;
            mid = N/2;
            atual = vet[mid]+1;

            for(i=mid+1;i<N;i++){
                walk += (vet[i]-atual);
                atual++;
            }
            atual = vet[mid]-1;
            for(i=mid-1; i>=0 ;i--){
                walk += (atual-vet[i]);
                atual--;
            }
            printf("%lld\n", walk);
        }
    }

    return 0;
}

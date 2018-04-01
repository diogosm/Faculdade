#include<iostream>
#include<math.h>
#include<time.h>
#include<vector>

using namespace std;

int main(){

    int primos[3500];
    int cont = 0;
    int t;
    unsigned long long int m,n;

    primos[cont++] = 2;
    for (int i = 3; i <= 32000; i+=2) {     //sqrt(10^9) =~ 31 mil
        bool ehprime = true;
        int cap = sqrt(i) + 1;

        for (int j = 0; j < cont; j++) {
            if (primos[j] >= cap) break;
            if (i % primos[j] == 0) {
                ehprime = false;
                break;
            }
        }
        if (ehprime) primos[cont++] = i;
    }
    //for(int i = 0;i<cont;i++){
        //printf("%d\n", primos[i]);
        //getchar();
    //}

    cin >> t;
    int k;
    int ini;
    while(t!=0){

        cin>>m>>n;

        int vet[100001];
        for(int i = 0;i< 100001;i++)
            vet[i] = 1;

        /**  **/
        for(int i = 0; i<cont;i++){
            k = primos[i];

            if(k>=m){ ini = k*2; }
            else{ ini = m + ((k-m%k)%k); }

            for(int u = ini;u<=n;u+=k){
                cout<<u-m<<endl;
                getchar();
                vet[u-m] = 0;
            }
        }
        for(int i = m; i <= n; i++){
            if (vet[i-m]==1 && i != 1) cout<<i<<endl;
        }

        t--;
    }
    return 0;
}

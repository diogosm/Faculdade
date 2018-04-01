#include<iostream>
#define f(i,a,b) for(int i=a;i<=b;i++)
using namespace std;int v[200][200],m,t,n;
int main(){cin>>t;
f(i,1,t){cin>>n;m=0;
f(j,1,n)f(k,1,j){cin>>v[j][k];(v[j][k]=max(v[j-1][k-1],v[j-1][k])+v[j][k])>m?m=v[j][k]:m;}
cout<<m<<endl;
}
}

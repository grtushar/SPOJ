#include<bits/stdc++.h>
using namespace std;
#define y long long
#define N 13000000
#define b push_back
bool p[N];vector<y>ps;void s(){y i=3,j,q=sqrt(N);ps.b(2);for(;i<=q;i+=2){if(p[i]==false){ps.b(i);for(j=i*i;j<N;j+=2*i)p[j]=true;}}while(i<N){if(p[i]==false)ps.b(i);i+=2;}}int main(){y n;s();while(scanf("%lld",&n)==1){cout<<ps[n-1]<<endl;}}

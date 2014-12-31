using namespace std;

#include<iostream>
#include<cstdio>

int main()
{
        int t,n,d,a;
        scanf("%d",&t);

        while(t--)
        {
                scanf("%d%d%d",&n,&a,&d);

                int ans = d*(((n-1)*n)/2)+(n*a);
                cout<<ans<<endl;
        }

        return 0;
}

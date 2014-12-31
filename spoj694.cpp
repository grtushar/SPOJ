using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>

char str[1000+10];

bool cmp(int a, int b)
{
        return strcmp(str+a,str+b)<0;
}

int main()
{
        int n,i,t,sa[1000+10],lcp[1000+10],ans,cnt,x,y;
        scanf("%d",&t);

        while(t--)
        {
                cin>>str;
                n=strlen(str);

                for(i=0;i<n;i++) sa[i]=i;

                sort(sa,sa+n,cmp);

                lcp[0]=0;
                for(i=1;i<n;i++)
                {
                        cnt=0;
                        for(x=sa[i],y=sa[i-1];str[x]==str[y];x++,y++)
                                cnt++;
                        lcp[i]=cnt;
                }

                ans=0;
                for(i=0;i<n;i++)
                {
                        ans+=(n-sa[i])-lcp[i];
                }

                cout<<ans<<endl;

                /*for(i=0;i<n;i++)
                        cout<<sa[i]<<endl;*/
        }

        return 0;
}

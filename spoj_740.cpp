using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>

#define max(a,b) ((a>b)?(a):(b))

int dp[2010][2010],arr[2010],n;

int solve(int left, int right, int i)
{
        if(left>right||i>n)
                return 0;

        if(dp[left][right]!=-1)
                return dp[left][right];

         int r1 = arr[left]*i+solve(left+1,right,i+1);
         int r2 = arr[right]*i+solve(left,right-1,i+1);
         return dp[left][right] = max(r1,r2);
}

int main()
{
        int i;

        while(scanf("%d",&n)==1)
        {
                for(i=0;i<n;i++)
                        scanf("%d",&arr[i]);

                memset(dp,-1,sizeof(dp));

                printf("%d\n",solve(0,n-1,1));
        }

        return 0;
}



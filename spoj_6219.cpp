using namespace std;

#include<iostream>
#include<string.h>
#include<cstdio>

#define min(a,b) ((a<b)?(a):(b))

int dp[2010][2010];

int main()
{
        int t,i,j;
        char str1[2010],str2[2010];
        scanf("%d",&t);

        while(t--)
        {
                scanf("%s%s",str1,str2);

                int l1 = strlen(str1);
                int l2 = strlen(str2);

                for(i=0;i<l1;i++)
                        dp[i][0]=i;
                for(i=0;i<l2;i++)
                        dp[0][i]=i;

                for(i=1;i<=l1;i++)
                {
                        for(j=1;j<=l2;j++)
                        {
                                if(str1[i-1]==str2[j-1])
                                {
                                        dp[i][j]=dp[i-1][j-1];
                                }
                                else
                                {
                                        dp[i][j]=min(dp[i-1][j-1]+1, min(dp[i-1][j]+1,dp[i][j-1]+1));
                                }
                        }
                }

                printf("%d\n",dp[l1][l2]);
        }

        return 0;
}


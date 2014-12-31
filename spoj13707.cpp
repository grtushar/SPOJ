using namespace std;

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

#define n 20050
#define min(a,b) ((a<b)?(a):(b))

bool check[n];
int arr[n]={0};

int main()
{
    int q,x,count=0;
    scanf("%d",&q);

    while(q--)
    {
        scanf("%d",&x);
        arr[x]=1;

        if(arr[x-1]&&arr[x+1])
            count-=1;
        else if(arr[x-1]||arr[x+1])
            count=count;
        else
            count+=1;

        cout<<count<<endl;
    }

    cout<<"Justice"<<endl;
    return 0;
}
/*
int main()
{
    memset(check,false,sizeof(check));
    int q,x,count=0,te;
    scanf("%d",&q);

    while(q--)
    {
        scanf("%d",&x);
        check[x]=true;

        if(check[x-1]==false&&check[x+1]==false)
        {
            count++;
            arr[x]=count;
        }

        else if(check[x-1]&&check[x+1])
        {
            arr[x]=min(arr[x-1],arr[x+1]);
            count=arr[x];

            if(count==arr[x+1])
            {
                te=x-1;
                while(check[te])
                {
                    arr[te]=count;
                    te--;
                }
            }
            else
            {
                te=x+1;
                while(check[te])
                {
                    arr[te]=count;
                    te++;
                }
            }

        }

        else if(check[x-1])
        {
            arr[x]=arr[x-1];
        }

        else if(check[x+1])
        {
            arr[x]=arr[x+1];
        }

        cout<<count<<endl;
    }

    cout<<"Justice"<<endl;

    return 0;
}
*/


using namespace std;

#include<iostream>
#include<cstdio>
#include<algorithm>

#define mx 5050
#define INF 99999

typedef struct edge
 {
    int u,v,w;
    edge( int a ,int b, int c){
        u = a , v = b , w = c;
    }
    edge(){};
    // constructor
}E;

int prev[mx];


int Parent(int i)
 {
    if(i==prev[i])return i;

    return prev[i]=Parent(prev[i]);
}

int Link(int a,int b)
 {
    return Parent(a)==Parent(b);
}

void makeUnion(int a,int b )
 {
    prev[Parent(a)] = Parent(b);
}


bool cmp (edge a ,edge b)
 {
    return a.w < b.w ; // sorting acesnding by edge
}


int main()
 {
    int test ,n,e,i,j;
    E x[mx];


        scanf("%d %d",&n,&e);

        for( i = 0 ; i < e ;i++)
        {
            int u , v , w ;
            cin >> u >> v >> w ;
            x[i] = edge(u,v,w);
        }
        sort(x,x+e,cmp);

        for(i = 1 ; i <= n ; i++ ) prev[ i ] = i ; // making each node its own parent

        int mst = 0 ;


        for(i=0;i<e ;i++)
        {
            if(!Link(x[i].u,x[i].v))
            {
                makeUnion(x[i].u,x[i].v);
                mst += x[i].w;
            }
        }
        printf("%d\n",mst);


    return 0;
}

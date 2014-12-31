using namespace std;

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>

int cost[10000+10],max_v,node;
vector<int>graph[10000+10];
bool visited[10000+10];

void bfs(int s)
{
          memset(visited,false, sizeof(visited));
        max_v=0;
        node=s;
        visited[s]=true;
        cost[s]=0;
        queue<int>Q;
        Q.push(s);

        while(!Q.empty())
        {
                int u = Q.front();
                Q.pop();

                for(int i=0;i<graph[u].size();i++)
                {
                        int v = graph[u][i];
                        if(visited[v]==false)
                        {
                                visited[v]=true;
                                cost[v]=cost[u]+1;

                                if(cost[v]>max_v)
                                {
                                        node=v;
                                        max_v=cost[v];
                                }
                                Q.push(v);
                        }
                }
        }
}

int bfs2(int s, int d)
{
        memset(visited,false,sizeof(visited));
        visited[s]=true;
        queue<int>Q;
        Q.push(s);

        while(!Q.empty())
        {
                 int u = Q.front();
                Q.pop();

                for(int i=0;i<graph[u].size();i++)
                {
                        int v = graph[u][i];
                        if(visited[v]==false)
                        {
                                visited[v]=true;
                                cost[v]=cost[u]+1;

                                if(v==d)
                                        return cost[v];
                                Q.push(v);
                        }
                }
        }
}

int main()
{
        int n,u,v,i;

        while(scanf("%d",&n)!=EOF)
        {
                for(i=0;i<n-1;i++)
                {
                        scanf("%d%d",&u,&v);
                        graph[u].push_back(v);
                        graph[v].push_back(u);
                }

                bfs(1);
               // ans+=max_v;
                int node1=node;
                bfs(node);
                int node2=node;
               // ans+=max_v;
                    int ans=bfs2(node1,node2);

                printf("%d\n",ans);
        }

        return 0;
}

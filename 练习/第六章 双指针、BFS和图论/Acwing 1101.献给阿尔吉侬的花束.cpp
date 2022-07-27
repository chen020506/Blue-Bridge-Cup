//  时间：2022.07.27  12点05分
//  算法：BFS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

#define x first
#define y second

typedef pair<int,int> PII;
const int N=210;
int n,m;
char g[N][N];
int dist[N][N];

int bfs(PII start,PII end)
{
    queue<PII> q;
    memset(dist,-1,sizeof dist);
    dist[start.x][start.y]=0;
    
    q.push(start);
    
    int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
    
    while(q.size())
    {
        PII t=q.front();
        q.pop();
        if(t==end) return dist[t.x][t.y];
        
        for(int i=0;i<4;i++)
        {
            int x=t.x+dx[i],y=t.y+dy[i];
            if(x<0||x>=n||y<0||y>=m) continue;//出界
            if(g[x][y]=='#') continue;//障碍物
            if(dist[x][y]!=-1) continue;//之前已经走过
            
            dist[x][y]=dist[t.x][t.y]+1;
            q.push({x,y});
        }
    }
    return -1;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++) scanf("%s",g[i]);
        
        //找到起点和终点
        PII start,end;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(g[i][j]=='S') start={i,j};
                else if(g[i][j]=='E') end={i,j};
                
        int t=bfs(start,end);
        if(t==-1) puts("oop!");
        else printf("%d\n",t);
    }
    return 0;
}
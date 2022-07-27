//  时间:2022.07.27  19点08分
//  算法：BFS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int N=110;
struct Point
{
    int x,y,z;
};
int L,R,C;
char g[N][N][N];
Point q[N*N*N];
int dist[N][N][N];

int dx[6]={1,-1,0,0,0,0};
int dy[6]={0,0,1,-1,0,0};
int dz[6]={0,0,0,0,1,-1};
int bfs(Point start,Point end)
{
    int hh=0,tt=0;
    q[0]=start;
    memset(dist,-1,sizeof dist);
    dist[start.x][start.y][start.z]=0;
    
    while(hh<=tt)
    {
        auto t=q[hh++];
        for(int i=0;i<6;i++)
        {
            int x=t.x+dx[i];
            int y=t.y+dy[i];
            int z=t.z+dz[i];
            if(x<0||x>=L||y<0||y>=R||z<0||z>=C) continue;//出界
            if(g[x][y][z]=='#') continue;//障碍物
            if(dist[x][y][z]!=-1) continue;//之前走过
            dist[x][y][z]=dist[t.x][t.y][t.z]+1;
            if(x==end.x&&y==end.y&&z==end.z) return dist[x][y][z];
            
            q[++tt]={x,y,z};
            
        }
    }
    return -1;
}
int main ()
{
    while(scanf("%d%d%d",&L,&R,&C),L||R||C)
    {
        Point start,end;
        for(int i=0;i<L;i++)
            for(int j=0;j<R;j++)
                {
                    scanf("%s",&g[i][j]);
                    for(int k=0;k<C;k++)
                    {
                        char c=g[i][j][k];
                        if(c=='S') start={i,j,k};
                        else if (c=='E') end={i,j,k};
                    }
                }
                
        int dist=bfs(start,end);
        if(dist==-1) puts("Trapped!");
        else printf("Escaped in %d minute(s).\n",dist);
    }
    return 0;
}
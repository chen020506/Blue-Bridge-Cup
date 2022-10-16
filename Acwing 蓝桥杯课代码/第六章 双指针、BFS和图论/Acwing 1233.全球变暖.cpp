//  时间:2022.07.27  22点36分
//  算法：flood fill DFS BFS
//  来源：第九届蓝桥杯省赛C++ A/B组
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

#define x first
#define y second

typedef pair<int,int> PII;
const int N=1010;
int n;
char g[N][N];
bool st[N][N];
PII q[N*N];
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
void bfs(int sx,int sy,int& total,int &bound)
{
    int hh=0,tt=0;
    q[0]={sx,sy};
    st[sx][sy]=true;
    while(hh<=tt)
    {
        PII t=q[hh++];
        total++;
        bool is_bound=false;
        for(int i=0;i<4;i++)
        {
         int x=t.x+dx[i],y=t.y+dy[i];
         if(x<0||x>=n||y<0||y>=n) continue;//出界
         if(st[x][y]) continue;
         if(g[x][y]=='.')
         {
             is_bound=true;
             continue;
         }
         q[++tt]={x,y};
         st[x][y]=true;
        }
        if(is_bound) bound++;
     }
}
int main ()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%s",g[i]);
    int cnt=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(!st[i][j]&&g[i][j]=='#')
            {
                int total=0,bound=0;
                bfs(i,j,total,bound);
                if(total==bound) cnt++;//如果一个岛屿陆地的数量和边界陆地的数量相等，则这个岛屿一定会被淹没
                
            }
    printf("%d\n",cnt);
    return 0;
}
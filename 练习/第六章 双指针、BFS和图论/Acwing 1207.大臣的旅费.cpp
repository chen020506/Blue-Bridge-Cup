//  时间：2022.07.27  23点46分
//  来源：第四届蓝桥杯省赛C++ A组
//  算法：树的直径问题：题目中描述图连通，且有n-1条边
//。则对于一个连通块，我们可以选择从任意起点出发，求距该起点最远的点，
//记为newStart。然后再从newStart出发，求距离newStart最远的点，这个距离就是图中任意两点距离中的最大
//值。然后再算花费即可。
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int N=100010;
int n;
struct Edge
{
  int id,w;  
};

vector<Edge> h[N];
int dist[N];

void dfs(int u,int father,int distance)
{
    dist[u]=distance;
    for(auto node:h[u])
    {
        if(node.id!=father) 
        {
            dfs(node.id,u,distance+node.w);
        }
        
    }
}
int main ()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        h[a].push_back({b,c});
        h[b].push_back({a,c});
    }
    dfs(1,-1,0);
    int u=1;
    for(int i=1;i<=n;i++)
        if(dist[i]>dist[u])
            u=i;
    dfs(u,-1,0);
    for(int i=1;i<=n;i++)
        if(dist[i]>dist[u])
            u=i;
    int s=dist[u];
    printf("%lld\n",s*10+s*(s+1ll)/2);
    return 0;
}

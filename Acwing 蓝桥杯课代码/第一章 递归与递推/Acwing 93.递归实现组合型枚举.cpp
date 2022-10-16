//  时间：2022.07.20 18点54分
//  算法：递归 dfs
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int N=30;
int n,m;
int ways[N];
void dfs(int u,int start)
{//start表示当前最小可以从哪个数开始枚举
    if(u+n-start<m) return;//优化 剪枝
    //如果把后面数都选上都不够m个，则直接退出
    if(u>m) {
        for(int i=1;i<=m;i++) printf("%d ",ways[i]);
        puts("");
        return;
    }
    for(int i=start;i<=n;i++)
    {
        ways[u]=i;
        dfs(u+1,i+1);
        ways[u]=0;//恢复现场 可写可不写
    }
}
int main ()
{
    scanf("%d %d",&n,&m);
    
    dfs(1,1);
    return 0;
}
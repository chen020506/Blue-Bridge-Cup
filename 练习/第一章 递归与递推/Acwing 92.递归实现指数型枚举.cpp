// 时间：2022.07.20 12点29分
// 算法：递归
#include<iostream>
#include<cstdio>
using namespace std;
const int N=16;
int n;
int st[N];//每一位的状态共三种：1表示选它2表示不选0表示还未选择
void dfs(int u)
{
    if(u>n) //已经到达递归的终点即得到了一种方案数
    {
        //遍历输出这个方案
        for(int i=1;i<=n;i++)
            if(st[i]==1)
                printf("%d ",i);
        printf("\n");
        return ;
    }
    
    st[u]=1;//第一个分支 选择它
    dfs(u+1);
    st[u]=0;//恢复现场
    
    st[u]=2;//第二个分支 不选它
    dfs(u+1);
    st[u]=0;//恢复现场
}
int main ()
{
    cin>>n;
    
    dfs(1);//从第1位开始递归
    return 0;
}
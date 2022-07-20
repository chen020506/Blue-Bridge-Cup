//  时间；2022.07.20 13点02分
// 算法：递归
#include<iostream>
using namespace std;

const int N=10;

int n;
int st[N];//0表示还没放数 1~n表示放了哪个数
bool used[N];//true表示用过，false表示还没用过

void dfs(int u)
{
    if(u>n)//到达边界
    {
        for(int i=1;i<=n;i++) printf("%d ",st[i]);
        printf("\n");
        return ;
    }
    
    for(int i=1;i<=n;i++)
        if(!used[i])
        {
            st[u]=i;
            used[i]=true;
            dfs(u+1);
            
            st[u]=0;
            used[i]=false;
        }
}
int main ()
{
    cin>>n;
    dfs(1);
    return 0;
}
//  时间：2022.08.14  21点34分
//  算法：DFS 模拟
#include<bits/stdc++.h>
using namespace std;

char arr[11][11];
bool st[11][11];//状态数组，用来表示哪个点已经搜索过了
int res=0;
void dfs(int x,int y)
{
    if(st[x][y]) return;//如果这个点之前已经被搜索过了，则退出
    if(x<1||x>10||y<1||y>10){ //能出去的情况
        res++;
        return;}
    st[x][y]=true;
    if(arr[x][y]=='U') dfs(x-1,y);
    if(arr[x][y]=='D') dfs(x+1,y);
    if(arr[x][y]=='L') dfs(x,y-1);
    if(arr[x][y]=='R') dfs(x,y+1);
}
int main ()
{
    for(int i=1;i<=10;i++) 
        for(int j=1;j<=10;j++)
            cin>>arr[i][j];
    for(int i=1;i<=10;i++)
        for(int j=1;j<=10;j++){
            memset(st,0,sizeof st);//每次必须将状态数组初始化      
            dfs(i,j);
        }
    cout<<res<<endl;
    return 0;
}
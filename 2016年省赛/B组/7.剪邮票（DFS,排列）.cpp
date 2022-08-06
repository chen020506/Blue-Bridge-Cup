//  时间：2022.08.06  23点06分
//  算法:枚举 dfs
#include<bits/stdc++.h>
using namespace std;

int a[]={0,0,0,0,0,0,0,1,1,1,1,1};
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int ans;
int mmap[3][4];
void dfs(int x,int y)
{
    mmap[x][y]=0;//将搜索过的点直接置为0，可以少用一个判重数组，好方法
    for(int i=0;i<4;i++)
    {
        int tx=x+dx[i];
        int ty=y+dy[i];
        if(tx<0||tx>=3||ty<0||ty>=4) continue;//越界
        if(mmap[tx][ty]==0) continue;//不符号要求
        dfs(tx,ty);
    }
}
bool check()
{
    for(int i=0;i<3;i++)    
        for(int j=0;j<4;j++)
        //将排列好的数列转换成二维数组
            mmap[i][j]=a[4*i+j];
    int cnt=0;//记录连通块的数量
    for(int i=0;i<3;i++)
        for(int j=0;j<4;j++)
            if(mmap[i][j]==1){//如果是枚举到的剪的位置
                dfs(i,j);
                cnt++;
            }
    if(cnt==1) return true;//如果只有一个连通块，则是成功的答案
    return false;
}
int main ()
{
    do
    {
        if(check()) ans++;//检查是否只有一个连通块
    }while(next_permutation(a,a+12));
    
    cout<<ans<<endl;
    return 0;
}
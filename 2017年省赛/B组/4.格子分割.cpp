//  时间：2022.08.11  21点10分
//  算法：DFS+回溯
//  思路：从中心点开始搜，每次都是对称的搜
#include<bits/stdc++.h>

using namespace std;

int mmap[7][7];
int ans=0;
int dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};
void dfs(int x,int y)
{
    //边界情况
    if(x==0||y==0||x==6||y==6)
    {
        ans++;
        return;
    }
    mmap[x][y]=1;
    mmap[6-x][6-y]=1;
    for(int i=0;i<4;i++)
    {
        int tx=x+dx[i];
        int ty=y+dy[i];
        
        if(tx>-1&&tx<7&&ty>-1&&ty<7&&mmap[tx][ty]==0)
            dfs(tx,ty);
    }
    mmap[x][y]=0;
    mmap[6-x][6-y]=0;
}

int main ()
{
    dfs(3,3);
    cout<<ans/4<<endl;
    //除以4是因为旋转对称是属于一种 所以相当于一种方案被算了四次
    return 0;
}
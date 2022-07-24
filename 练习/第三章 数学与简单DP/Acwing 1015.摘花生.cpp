//  时间：2022.07.24  23点25分
//  算法：DP 01背包 第一个自己独立写出来的DP哈哈
#include<iostream>
#include<algorithm>

using namespace std;

const int N=110;
int g[N][N];
int t,r,c;
int f[N][N];
int main ()
{
    cin>>t;
    while(t--)
    {
        cin>>r>>c;
        for(int i=1;i<=r;i++)
            for(int j=1;j<=c;j++) cin>>g[i][j];
        for(int i=1;i<=r;i++)
            for(int j=1;j<=c;j++)
            {
                f[i][j]=max(f[i-1][j]+g[i][j],f[i][j-1]+g[i][j]);
            }
            cout<<f[r][c]<<endl;
    }
    return 0;
}
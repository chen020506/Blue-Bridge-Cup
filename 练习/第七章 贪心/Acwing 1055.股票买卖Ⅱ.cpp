//  时间：2022.07.28  09点55分
//  算法：贪心 DP 线性DP 状态机
//  思路：遇涨则买
#include<iostream>
#include<cstdio>
using namespace std;
const int N=100010;
int n;
int a[N];
int main ()
{
    cin>>n;
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    
    int res=0;
    for(int i=0;i+1<n;i++)
    {
        if(a[i+1]>a[i]) res+=a[i+1]-a[i];
    }
    
    cout<<res<<endl;
    return 0;
}
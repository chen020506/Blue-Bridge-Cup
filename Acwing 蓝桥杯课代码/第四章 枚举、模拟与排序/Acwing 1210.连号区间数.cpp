//  时间：2022.07.25  16点38分
//  算法：模拟
//  来源：第四届蓝桥杯省赛C++ B组
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
  
const int N=50010,INF=99999999;
  
int a[N];
  
int main (){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)  cin>>a[i];
    int res=0;
    for(int i=1;i<=n;i++)//枚举区间左端点
    {
        int mmin=INF,mmax=-INF;
        for(int j=i;j<=n;j++)//枚举区间内右端点
            {
                mmin=min(mmin,a[j]);
                mmax=max(mmax,a[j]);
                if(mmax-mmin==j-i) res++;//连号区间的性质，而且可以不用排序
            }
    }
    cout<<res<<endl;
    return 0;
}
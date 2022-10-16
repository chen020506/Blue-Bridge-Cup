//  时间：2022.07.27  18点40分
//  来源：第十届蓝桥杯省赛C++ A/B组
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

typedef long long LL;
const int N=100010;
int n;
int a[N];
int main ()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    
    
    LL maxs=-1e18;
    int depth=0;
    for(int d=1,i=1;i<=n;i*=2,d++)
    {
        LL s=0;
        for(int j=i;j<i*2&&j<=n;j++)
            s+=a[j];
        if(s>maxs)
            {
                maxs=s;
                depth=d;
            }
    }
    printf("%d\n",depth);
    return 0;
}
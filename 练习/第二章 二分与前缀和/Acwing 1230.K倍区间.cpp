// 时间：2022.07.23  16点30分
//  算法：前缀和
//  来源：第八届蓝桥杯省赛C++B组
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;

const int N=100010;
int n,k;
LL s[N],cnt[N];

int main ()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&s[i]);
        s[i]+=s[i-1];
    }
    LL res=0;
    cnt[0]=1;//s[0]%k是0，所以余数为0的数初始化为1
    for(int i=1;i<=n;i++)
    {
        res+=cnt[s[i]%k];
        cnt[s[i]%k]++;
    }
    printf("%lld\n",res);
    return 0;
}

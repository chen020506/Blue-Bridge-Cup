// 时间：2022.08.14  19点59分
//  算法：前缀和
//  思路：我们将前缀和对K取余，那么得到[0, K-1]共K种余数，
//      易知对K取余得相同余数的两个数做差，得到的值肯定是K的倍数。
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;

const int N=100010;
int n,k;
LL s[N],cnt[N];//cnt数组：cnt[x]表示余数为x的个数

int main ()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&s[i]);
        s[i]+=s[i-1];//求出前缀和
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

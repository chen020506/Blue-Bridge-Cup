//  时间：2022.07.28  10点25分
//  算法：排序 贪心 绝对值不等式
//  思路：排序找到中位数
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
const int N=100010;
typedef long long LL;
int n;
int x[N];
int main ()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&x[i]);
    
    sort(x,x+n);
    int c=x[n/2];
    LL res=0;
    for(int i=0;i<n;i++) res+=abs(x[i]-c);
    
    printf("%lld\n",res);
    return 0;
}
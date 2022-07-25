//  时间：2022.07.25 18点10分
//  算法：模拟 二分 前缀和
//  来源：第九届蓝桥杯省赛C++ B组

#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

typedef long long LL;
const int N=100010;
int a[N],b[N],c[N];
int n;
int as[N]; //as[i]表示在a[]中有多少数小于b[i]
int cs[N]; //cs[i]表示在c[]中有多少数大于b[i]
int cnt[N],s[N];
int main()
{
    cin>>n;
    for(int j=0;j<n;j++) scanf("%d",&a[j]),a[j]++;

    for(int j=0;j<n;j++) scanf("%d",&b[j]),b[j]++;

    for(int j=0;j<n;j++) scanf("%d",&c[j]),c[j]++;

        //求as[]
    for(int i=0;i<n;i++) cnt[a[i]]++;
    for(int i=1;i<N;i++) s[i]=s[i-1]+cnt[i];//求cnt[]的前缀和
    for(int i=0;i<n;i++) as[i]=s[b[i]-1];
    
        //求cs[]
    memset(cnt,0,sizeof cnt),memset(s,0,sizeof s);
    for(int i=0;i<n;i++) cnt[c[i]]++;
    for(int i=1;i<N;i++) s[i]=s[i-1]+cnt[i];
    for(int i=0;i<n;i++) cs[i]=s[N-1]-s[b[i]];    
    
    //枚举每个b[i]
    LL res=0;
    for(int i=0;i<n;i++)
        res+=(LL)as[i]*cs[i];
    cout<<res<<endl;
    return 0;
}
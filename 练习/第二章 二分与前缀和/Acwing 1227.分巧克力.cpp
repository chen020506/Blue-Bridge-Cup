//  时间：2022.07.23 10点34分
//  来源：第八届蓝桥杯省赛C++A/B组,第八届蓝桥杯省赛JAVAA/B组
//  算法：二分
#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
int n,k;
const int N=100010;
int h[N],w[N];
bool check(int mid)
{
    int res=0;//总块数
    for(int i=0;i<n;i++)
    {
        res+=(h[i]/mid)*(w[i]/mid);
        if(res>=k) return true;//总块数大于k，那么此时边长一定不是最大值
    }
    return false;
}
int main (){
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++) scanf("%d%d",&h[i],&w[i]);
    
    int l=1,r=1e5;
    while(l<r)
    {
        int mid=l+r+1>>1;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    printf("%d\n",r);
}
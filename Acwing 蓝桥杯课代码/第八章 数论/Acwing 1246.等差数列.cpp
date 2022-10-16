//  时间：2022.07.28  13点59分
//  算法：辗转相除法求最大公约数 欧几里得算法
//  来源：第十届蓝桥杯省赛C++ B组
#include<iostream>
#include<algorithm>
using namespace std;

const int N=100010;
int n;
int a[N];
int gcd(int a,int b)
{
    return b? gcd(b,a%b):a;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    
    sort(a,a+n);
    
    int d=0;
    for(int i=1;i<n;i++) d=gcd(d,a[i]-a[i-1]);
    
    if(!d)  printf("%d\n",n);
    else printf("%d\n",(a[n-1]-a[0])/d +1);
    return 0; 
}
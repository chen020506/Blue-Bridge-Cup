//  时间：2022.07.28 23点07分
#include<iostream>
using namespace std;
typedef long long LL;

int main ()
{
    LL a,b,n;
    cin>>a>>b>>n;
    LL res=0;//最后的答案
    LL t=5*a+2*b;//每周可以做的总题目数
    res+=7*(n/t);

    n%=t;
    for(int i=1;i<=5&&n>0;i++) res++,n-=a;
    for(int i=1;i<=2&&n>0;i++) res++,n-=b;
    printf("%lld\n",res);
    return 0;
}
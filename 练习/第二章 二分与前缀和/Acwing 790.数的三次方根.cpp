//  时间：2022.07.22 12点49分
//  算法：实数二分
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main ()
{
    double x;
    cin>>x;
    double l=-10000,r=10000;
    while(r-l>1e-8)
    {
        double mid=(l+r)/2;
        if(mid*mid*mid>=x) r=mid;
        else l=mid;
    }
    printf("%lf",l);
}
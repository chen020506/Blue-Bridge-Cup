//  时间：2022.07.22 23点02分
//  算法：二分
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

const int N=2500010;
// 第一种 暴力三重循环
// int n;
// int main ()
// {
//     cin>>n;
//     for(int a=0;a*a<=n;a++)
//         for(int b=a;a*a+b*b<=n;b++)
//             for(int c=b;a*a+b*b+c*c<=n;c++)
//             {
//                 int t=n-a*a-b*b-c*c;
//                 int d=sqrt(t);
//                 if(d*d==t)
//                 {
//                     printf("%d %d %d %d\n",a,b,c,d);
//                     return 0;
//                 }
//             }
// }

//  第二种：二分写法
int n,m;
struct Sum
{
    int s,c,d;
    bool operator<(const Sum&t)
    {
        if(s!=t.s) return s<t.s;
        if(c!=t.c) return c<t.c;
        return d<t.d;
    }
}sum[N];
int main ()
{
    cin>>n;
    
    for(int c=0;c*c<=n;c++)
        for(int d=c;c*c+d*d<=n;d++)
            sum[m++]={c*c+d*d,c,d};
    sort(sum,sum+m);
    
    for(int a=0;a*a<=n;a++)
        for(int b=a;a*a+b*b<=n;b++)
        {
            int t=n-a*a-b*b;
            int l=0,r=m-1;
            while(l<r)
            {
                int mid=l+r >>1;
                if(sum[mid].s>=t) r=mid;
                else l=mid+1;
            }
            if(sum[l].s==t)
            {
                printf("%d %d %d %d\n",a,b,sum[l].c,sum[l].d);
                return 0;
                
            }
        }
}
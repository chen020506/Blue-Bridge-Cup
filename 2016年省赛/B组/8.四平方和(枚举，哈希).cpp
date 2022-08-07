//  时间：2022.08.07  15点21分
//  思路：先枚举c*c+d*d,将结果存到数组里面，然后枚举a,b
//  如果n-a*a+b*b在数组里面能找到对应的值，则输出
#include<bits/stdc++.h>
using namespace std;

const int N=5000010;
int n;
int C[N],D[N];

int main ()
{
    scanf("%d",&n);
    memset(C,-1,sizeof C);//初始化为-1则表示这个值没有枚举出来
    
    for(int c=0;c*c<=n;c++)
        for(int d=c;d*d+c*c<=n;d++)
            {
                int s=c*c+d*d;
                if(C[s]==-1)
                    C[s]=c,D[s]=d;
            }
    for(int a=0;a*a<=n;a++)
        for(int b=a;a*a+b*b<=n;b++)
        {
            int s=n-a*a-b*b;
            if(C[s]!=-1)
            {
                printf("%d %d %d %d",a,b,C[s],D[s]);
                return 0;
            }
        }
}
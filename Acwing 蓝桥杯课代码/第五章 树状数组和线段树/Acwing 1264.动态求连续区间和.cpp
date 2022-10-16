//  时间：2022.07.26  18点07分
//  算法：树状数组
#include<iostream>
using namespace std;

const int N=100010;
int a[N],tr[N];
int n,m;
int lowbit(int x)
{
    return x & -x;
}
void add(int x,int v)
{
    for(int i=x;i<=n;i+=lowbit(i)) tr[i]+=v;
}
int query(int x)
{
    int res=0;
    for(int i=x;i;i-=lowbit(i)) res+=tr[i];
    return res;
}
int main ()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    
    for(int i=1;i<=n;i++) add(i,a[i]);
    
    while(m--)
    {
        int k,x,y;
        scanf("%d%d%d",&k,&x,&y);
        if(k==0) printf("%d\n",query(y)-query(x-1));
        else add(x,y);
    }
    return 0;
}
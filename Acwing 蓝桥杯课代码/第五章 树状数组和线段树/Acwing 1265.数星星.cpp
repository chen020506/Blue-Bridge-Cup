//  时间：2022.07.26  20点15分
//  算法：树状数组
//  发现一篇挺好的题解：
//   https://www.acwing.com/solution/content/39139/
#include<iostream>
#include<algorithm>
using namespace std;

const int N=32010;

int n;
int tr[N],ans[N];
int lowbit(int x)
{
    return x& -x;
}
void add(int x)
{
    for(int i=x;i<N;i+=lowbit(i)) tr[i]++;
}
int sum(int x)
{
    int res=0;
    for(int i=x;i;i-=lowbit(i)) res+=tr[i];
    return res;
}
int main ()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) 
    {
        int x,y;
        scanf("%d%d",&x,&y);
         x++;
        ans[sum(x)]++;
        add(x);
    }
    for(int i=0;i<n;i++) printf("%d\n",ans[i]);
    return 0;
}
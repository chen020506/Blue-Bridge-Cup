//  时间：2022.08.07  15点59分
//  思路：从前到后扫描，如果这个位置上的数不符合要求
//  找到符合要求数的位置，交换一次，答案加一
#include<bits/stdc++.h>
using namespace std;

const int N=10010;
int n,res;
int a[N];
int get_pos(int x)
{
    for(int i=1;i<=n;i++)
        if(a[i]==x)
            return i;
    return -1;
}
int main ()
{
    cin>>n;
    for(int i=1;i<=n;i++) 
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=i){
            int pos=get_pos(i);
            swap(a[i],a[pos]);
            res++;
        }
    }
    cout<<res<<endl;
    return 0;
}
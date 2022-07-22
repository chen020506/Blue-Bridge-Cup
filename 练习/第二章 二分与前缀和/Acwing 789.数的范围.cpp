//  时间：2022.07.22 11点39分
//  算法：二分
//  终于掌握了整数二分的写法
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N=100010;
int n,q;
int a[N];
int main ()
{
    cin>>n>>q;
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    
    while(q--){
        int x;
        scanf("%d",&x);
        //二分x的左端点
        int l=0,r=n-1;//确定区间范围
        while(l<r)
        {
            int mid=l+r>>1;
            if(a[mid]>=x) r=mid;
            else l=mid+1;
        }
        if(a[l]==x)
        {
            cout<<r<<" ";//输出左端点的位置
            
            //二分x的右端点
            r=n-1;//右端点一定在[左端点，n-1]之间
            while(l<r)
            {
                int mid=l+r+1>>1;//防止死循环所以需要加1
                if(a[mid]<=x) l=mid;
                else r=mid-1;
            }
            cout<<r<<endl;
        }
        else
            cout<<"-1 -1"<<endl;
    }
    return 0;
}
//  时间:2022.08.07 17点58分
//  生成全排列然后检查
#include<bits/stdc++.h>
using namespace std;

int a[13]={1,2,3,4,5,6,7,8,9,10,11,12,13};
int res;
bool check()
{
    if(a[9]%a[10]!=0) return false;//不能整除
    if(a[0]+a[1]!=a[2]) return false;//加法
    if(a[3]-a[4]!=a[5]) return false;//减法
    if(a[6]*a[7]!=a[8]) return false;
    if(a[9]/a[10]!=a[11]) return false;
    
    return true;
}
void dfs(int x)
{
    if(x==13)//排列完毕
        if(check()) res++;
        
    for(int i=x;i<13;i++)
    {
        swap(a[x],a[i]);
        //剪枝 不满足加法和减法的跳过
        if(x==2&&a[0]+a[1]!=a[2]||(x==5&&a[3]-a[4]!=a[5]))
        {
            swap(a[x],a[i]);
            continue;
        }
        dfs(x+1);
        swap(a[x],a[i]);
    }
}
int main ()
{
    dfs(0);
    cout<<res<<endl;
    return 0;
}
//  第二种：用STL全排列函数，但是运行效率很慢
// int main ()
// {
//     // dfs(0);
//     do
//     {
//         if(check()) res++;
//     }while(next_permutation(a,a+13));
//     cout<<res<<endl;
//     return 0;
// }
//  时间：2022.07.20 20点16分
//  算法：递推
#include<iostream>
using namespace std;
int main ()
{
    int n;
    cin>>n;
    
    int f[46];
    f[1]=0,f[2]=1;
    //优化写法：可以不用开数组，用两个变量记录
    //int a=0,b=1;
    for(int i=3;i<=n;i++) f[i]=f[i-1]+f[i-2];
    //{
    //    f[i]=a+b;
    //    a=b;
    //    b=f[i];
    //}
    for(int i=1;i<=n;i++) printf("%d ",f[i]);
    return 0;
}
// 时间：2022.09.02 23点11分
// 思路：求出每个数因子2的个数和5的个数并求和 
//       取最小值然后求出零的个数
#include<bits/stdc++.h>
using namespace std;
    
int count_t=0,count_f=0;//count_t代表因子2的总个数
int work(int a)//求每个数因子2、5的个数
{
    int t=a;
    while(t%2==0) {count_t++;t/=2;}
    
    while(t%5==0) {count_f++;t/=5;}
}

int main ()
{

    int a;

     for(int i=1;i<=100;i++)
     {
         cin>>a;
         work(a);
     }

    cout<<min(count_f,count_t)<<endl;
}
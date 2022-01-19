// 时间：2022.1.12 20点57分
#include<iostream>
using namespace std;

int main()
{

    int n=1,m=2,res=0;//n代表当前层的煤球数，res代表总的煤球数
    for(int i=1;i<=100;i++)//100层
    {
        res+=n;
        n+=m;
        m++;//m代表每层煤球数目之间的差 
    }
    cout<<res<<endl;
    return 0;
    
}

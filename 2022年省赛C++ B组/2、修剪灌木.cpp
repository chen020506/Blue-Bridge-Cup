//  时间：2022.07.28 23点31分
//  思路：刚看到题吓一跳，但是仔细想想情况很简单
//  做一个简单的数学归纳既可以找到规律,树最高的情况就是
//  刚剪完这棵树然后直到它下次被剪
#include<iostream>
using namespace std;

int main ()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        if(i<=n/2)//如果在左边 那么最大的距离n-i
            cout<<((n-i)*2)<<endl;
        if(i>n/2)//如果在右边 那么最大的距离i-1
            cout<<((i-1)*2)<<endl;
    }
    return 0;
}
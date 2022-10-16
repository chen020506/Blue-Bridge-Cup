//  时间：2022.07.23  23点09分
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

int main()
{
   int n,res;
   cin>>n;
   res=n;
   while(n>=3)
   {
       res+=n/3;
       n=n/3+n%3;
   }
   cout<<res<<endl;
    return 0;
}
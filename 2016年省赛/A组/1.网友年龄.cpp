//  时间:2022.08.07  16点10分
#include<bits/stdc++.h>
using namespace std;

int res=0;
int main ()
{
    for(int i=10;i<=99;i++)
    {
        int a=i/10;
        int b=i%10;
        int s=b*10+a;
        if(i-s==27) res++;
    }
    cout<<res<<endl;
    return 0;
}
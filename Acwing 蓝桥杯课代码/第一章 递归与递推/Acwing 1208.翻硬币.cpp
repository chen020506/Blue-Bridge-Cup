//  时间：2022.07.21  22点40分
//  算法：递推
//  来源：第四届蓝桥杯省赛C++B组
#include<iostream>
#include<cstring>
using namespace std;

const int N=110;
char start[N],mend[N];
int n,res;
void turn(int i)
{
    if(start[i]=='*') start[i]='o';
    else start[i]='*';
}
int main ()
{
    cin>>start>>mend;
    
    n=strlen(start);
    
    for(int i=0;i<n;i++)
    {
        if(start[i]!=mend[i])
        {
            turn(i),turn(i+1);
            res++;
        }
    }
    cout<<res<<endl;
    return 0;
}
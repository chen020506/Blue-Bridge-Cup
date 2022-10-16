//  时间:2022.07.27  13点43分
//  来源：第七届蓝桥杯省赛C++ B组
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N=10010;
int n;
int b[N];
bool st[N];
int main ()
{
    cin>>n;
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    
    int cnt=0;
    for(int i=1;i<=n;i++)
        if(!st[i])
        {
            cnt++;
            for(int j=i;!st[j];j=b[j])
              st[j]=true;
        }
    printf("%d\n",n-cnt);
    
    return 0;
}
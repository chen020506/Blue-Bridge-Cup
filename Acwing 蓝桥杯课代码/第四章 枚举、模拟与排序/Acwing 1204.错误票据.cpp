//  时间：2022.07.25  20点19分
//  来源：第四届蓝桥杯C++ A/B组
#include<iostream>
#include<string>
#include<algorithm>
#include<sstream>
using namespace std;

const int N=10010;
int n;
int a[N];
int main()
{
    int cnt;
    cin>>cnt;
    string line;
    
    getchar();//忽略掉行数后面的回车
    while(cnt--)
    {
        getline(cin,line);
        stringstream ssin(line);
        
        while(ssin>>a[n]) n++;
    }
    
    sort(a,a+n);
    int res1=0,res2=0;
    for(int i=1;i<n;i++)
        if(a[i]==a[i-1]) res2=a[i];//重号
        else if(a[i]==a[i-1]+2) res1=a[i-1]+1;//断号
    cout<<res1<<" "<<res2<<endl;
    
    
    return 0;
}
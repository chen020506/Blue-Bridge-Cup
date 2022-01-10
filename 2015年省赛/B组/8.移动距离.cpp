// 时间：2022.1.10 18点13分 
#include<iostream>
#include<algorithm>

using namespace std;

int w,n,m;
int main ()
{
	cin>>w>>m>>n;
	
	int rm,rn;//m和n的行号
	int cm,cn;//m和n的列号
    //算两个数的行号
    if(m%w==0) rm=m/w;
    else rm=m/w+1;
   
    if(n%w==0) rn=n/w;
    else rn=n/w+1;
    
    int res=0;//记录答案
    //算两个数的列号
    
    //算m的列号
    if(rm%2==0)//偶数行，最大值在第一列
        cm=(rm *w)-m+1;//+1是为了让列数从1开始
    else //奇数行，最大值在最后一列
        cm=m-((w*rm)-w+1)+1;
  
  
    //算n的列号
    if(rn % 2==0)//偶数行，最大值在第一列
        cn=rn*w-n+1;//+1是为了让列数从1开始
    else //奇数行，最大值在最后一列
        cn=n-((w*rn)-w+1)+1;
    
    res+=abs(rm-rn);
   
    res+=abs(cm-cn);
    
    cout<<res<<endl;
	return 0;
} 

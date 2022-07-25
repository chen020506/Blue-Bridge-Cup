#include<iostream>
#include<cmath>
using namespace std;

int main ()
{
    int w,m,n;
    while(cin>>w>>m>>n){
    int row1,row2,col1,col2;
    row1=m/w;//m的行号
    if(row1==0) row1++;
    if(row1*w<m) row1++;
    row2=n/w;//n的行号
    if(row2==0) row2++;
    if(row2*w<n) row2++;
    //cout<<row1<<endl<<row2<<endl;
    //找到列号
    if(row1%2==0)//偶数行
    {
        int mmax=row1*w;//这一行的最大值
        col1=mmax-m+1;
    }
    if(row1%2!=0)//奇数行
    {
        int mmin=row1*w-w+1;
        col1=m-mmin+1;
        
    }
    if(row2%2==0)//偶数行
    {
        int mmax=row2*w;//这一行的最大值
        col2=mmax-n+1;
    }
    if(row2%2!=0)//奇数行
    {
        int mmin=row2*w-w+1;
        col2=n-mmin+1;
    }
    int res=abs(col1-col2)+abs(row1-row2);
    cout<<res<<endl;
    }
    return 0;
}
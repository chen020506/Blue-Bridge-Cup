// 时间：2022.1.12 16点10分
//由题意可知这个数的平方和立方的数字个数为10
//初步可以确定枚举的范围是从47到99

#include<iostream>
#include<cstring>
using namespace std;

bool flag;
int arr[11];
void cal(int x){
    while(x){
        arr[x%10]++;
        x=x/10;
    }
}
int main()
{
    for(int j=47;j<=99;j++){
        
       //下面这两步一定不能忘了，每次循环前恢复
        memset(arr,0,sizeof arr);
        flag=false;
        
        int n=j*j;
        int m=j*j*j;
        cal(n);
        cal(m);
        
    for(int i=0;i<=9;i++)
        if(arr[i]!=1) flag=true;
      
    if(flag==false) {
        cout<<j<<endl;
        return 0;
       }
      
    }
    return 0;
}

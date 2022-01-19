#include<iostream>
// 时间：2022.1.12 22点32分 
#include<algorithm>

using namespace std;

int a[]={1,2,3,4,5,6,7,8,9};

bool check()
{
    int x=a[3]*100+a[4]*10+a[5];
    int y=a[6]*100+a[7]*10+a[8];
   //注意此时的两个除法式必须合并到一块
   if((a[1]*y+a[2]*x)%(a[2]*y)!=0) return false;
   
   int t=a[0]+(a[1]*y+a[2]*x)/(a[2]*y);
   if(t==10) return true;
   return false;
}
int main()
{
    int res=0;
    do{
        if(check()) res++;
    }while(next_permutation(a,a+9));//全排列算法，字典序升序 
    cout<<res<<endl;
    return 0;
}

// 时间：2022.1.13 19点31分 
#include <stdio.h>
#define N 6
#define M 5
#define BUF 1024

void f(int a[], int k, int m, char b[])
{
    int i,j;

    if(k==N){
        b[M] = 0;//字符串结尾的标志 
        if(m==0) printf("%s\n",b);
        return;
    }
	//k是a数组的下标  m代表人数，初始为5 
    for(i=0; i<=a[k]; i++){//枚举第k个国家去的人数 
        for(j=0; j<i; j++) b[M-m+j] = k+'A';//填充字符串，有i人就填i个国家符号（k+'A） 
        f(a,k+1,m-i,b);  //m应当减去i, 因为第k个国家去了i个人 
    }
}
int main()
{
    int  a[N] = {4,2,2,1,1,3};
    char b[BUF];
    f(a,0,M,b);
    return 0;
}

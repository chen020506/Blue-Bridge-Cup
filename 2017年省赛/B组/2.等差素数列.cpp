//  时间：2022.08.09  22点17分
//  算法：模拟
#include<bits/stdc++.h>
using namespace std;

bool isPrime(int x)
{
	for(int i=2;i<sqrt(x);i++)
		if(x%i==0) return false;
	return true;
}
int main()
{
	int sum=1;
	int i,j,k,a;
	for(i=2;i<50000;i++)//枚举素数首项 
		if(isPrime(i))//如果是素数 
		{
		for(k=1;k<10000;k++)//枚举公差 
		for(int h=1;h<11;h++)//这里只运行九次，表示从首项开始的十个数 
		{
			a=i+h*k;
			if(isPrime(a)) sum++; 
			else 
				{
				sum=1;
				break;
				} //如果不是素数就跳出循环，找下一个公差 
			if(sum==10)//当有10个素数的时候，输出公差 
			{
				printf("%d\n",k);
				return 0;
			}	
		}
		}
	return 0;
}

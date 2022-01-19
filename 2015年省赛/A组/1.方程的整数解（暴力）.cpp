// 时间：2022.1.11 23点36分 
#include<iostream> 
using namespace std;

int main()
{
//通过估算可知三个数中任意一个数最大值不会超过32 
//因为题目要求输出最小的数，所以j和k的最小值可以不用
//从1开始，这样也避免了数据的重复输出 
	for(int i=1;i<=32;i++)
		for(int j=i;j<=32;j++){
			if(i*i+j*j>1000) continue; 
			for(int k=j;k<=32;k++)
				if(i*i+j*j+k*k==1000)
					cout<<"i= "<<i<<" j= "<<j<<" k= "<<k<<endl;
	}
	return 0;
}

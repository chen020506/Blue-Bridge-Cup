// 时间：2022.1.13 22点57分 
// 答案：1580 
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
//将二维数组拉成一维数组 
int arr[]={0,1,2,3,4,5,6,7,8,9};
//string arr="0123456789";  也可以使用string 
bool check(int x,int y)
{
	if(abs(arr[x]-arr[y])==1) return true;//连续的数字相邻返回真 
	return false;
 } 
int main()
{
	int res=0; 
	do
	{
		
		//判断横向的相邻
		 if(check(0,1)) continue;
		 if(check(1,2)) continue;
		 if(check(3,4)) continue;
		 if(check(4,5)) continue;
		 if(check(5,6)) continue;
		 if(check(7,8)) continue;
		 if(check(8,9)) continue;
		//判断纵向的相邻
		if(check(3,7)) continue;
		if(check(0,4)) continue;
		if(check(4,8)) continue;
		if(check(1,5)) continue;
		if(check(5,9)) continue;
		if(check(2,6)) continue;
		//判断主对角的相邻
		if(check(0,3)) continue; 
		if(check(1,4)) continue;
		if(check(4,7)) continue;
		if(check(2,5)) continue;
		if(check(5,8)) continue;
		if(check(6,9)) continue;
		//判断副对角线的相邻
		if(check(3,8)) continue; 
		if(check(4,9)) continue;
		if(check(0,5)) continue;
		if(check(1,6)) continue;
		 res++;
	}while(next_permutation(arr,arr+10));
	
	cout<<res<<endl; 
	return 0;
}

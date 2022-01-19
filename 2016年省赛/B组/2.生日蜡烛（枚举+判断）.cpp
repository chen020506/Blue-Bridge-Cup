// 时间：2022.1.12 21点09分 
#include<iostream>
using namespace std;
int main ()
{
	
	for(int i=1;i<=236;i++){//i表示从多少岁开始过生日 
		int res=0;
		for(int j=i;j<236;j++){//这个循环用来找到从i岁开始过生日是否能够236
		 	res+=j;
		 	if(res==236){
		 		cout<<i<<endl;
		 		return 0;
			 }
			
		} 
	}

	return 0; 
}

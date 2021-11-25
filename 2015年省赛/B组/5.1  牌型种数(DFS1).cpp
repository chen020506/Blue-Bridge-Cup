//  时间：2021.11.24  15点41分
//  算法：dfs 
#include<iostream>
using namespace std;

int cnt,sum;//cut代表方案的个数，sum代表手中的牌数
 
void dfs(int u){//牌的类型
	if(sum>13||u>13)  return; 
	if(sum==13){//判断手中的牌是否已经够了 
		cnt++;
		return;
	} 
	for(int i=0;i<=4;i++){
		sum+=i;
		dfs(u+1);
		sum-=i;
	} 
	
}
int main ()
{
	dfs(0);//注意此时是0 
	
	cout<<cnt<<endl;
	return 0; 
 } 

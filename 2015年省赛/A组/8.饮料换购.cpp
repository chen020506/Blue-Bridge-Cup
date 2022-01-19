// 时间：2022.1.12 20点16分 
#include<iostream>
using namespace std;

int n,res;//n表示当前的饮料数，res代表喝的饮料数 
int main ()
{
	cin>>n;
	while(n>=3){
		n=n-3+1;
		res+=3;
	}
	//最后还需要将不足3瓶的饮料喝掉
	res+=n; 
	cout<<res<<endl;
 } 

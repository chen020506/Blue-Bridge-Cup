// 时间：2022.1.12 17点03分 
#include<iostream>
#include<string>
#include<algorithm>
#include<vector> 
using namespace std;

int main()
{
	string s="aaabbbbccccc";
	vector<string>v1;
	int ans=0;
	do
	{
		//排除重复，对于v1中的每个元素进行检查，如果
		//存在s的旋转或者翻转，则跳过
		int i=0; 
		for(;i<v1.size();i++){
			if(v1[i].find(s)!=string::npos ) break;
		} 
		//s不可用的情况 
		if(i!=v1.size()) continue;
		string s2=s+s; 
		v1.push_back(s2); //s+s是为了解决字符串旋转问题
		//字符串s`是否是s的旋转等价于s`是否是s+s的字串 
		reverse(s2.begin(),s2.end());
		v1.push_back(s2);//将s的翻转放入vector中 
		
		ans++;
	}while(next_permutation(s.begin(),s.end()));
	cout<<ans<<endl;
	return 0;
}

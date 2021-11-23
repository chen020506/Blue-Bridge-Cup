//  时间：2021.11.23  21点05分
#include<iostream>
using namespace std;

int year,month,day,n;
int days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
//检查是不是闰年函数
bool check(int year) {
     if(year%400 == 0) return true;
     if(year%4==0 && year%100!=0) return true;
     return false;
} 
//判断数的合法性
bool test(int t)
{//第一步先先将数字转换为月份形式 
	int x=t%100;//日 
    int y=t/100%100;//月
	int z=t/10000;//年 
	
	if(y==0||y>12)  return false;
	if(x==0||(y!=2&&x>days[y]))  return false;
	
	if(y==2&&x>28+check(z))  return false;
	
	return true;
} 
int main ()
{
	
	while(cin>>year>>month>>day>>n){
		int s=year*10000+month*100+day;//先将最开始的日期转换成一个8位数
		int res=0,t=0;
		for(int i=s;i<=20200101;i++){//然后依次给这个数加一，检查其合法性 
			if(test(i)){
				res++;
				t=i;
			}
			if(res>n) break;
		}
		int x=t%100;//日 
		int y=t/100%100;//月
		int z=t/10000;//年 
		
		printf("%d-%02d-%02d\n",z,y,x); 
	}
    return 0;
 } 

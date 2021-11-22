//  时间：2021.11.22  22点28分
//优化思路通过算式可以推出a=9,c=b+1,e=1,f=0,g=8
//注意一定要排除掉数字相同的情况 
#include<iostream>
using namespace std;
int main ()
{
	int b,c,d,h;
	for(b=0;b<=9;b++)
	  for(c=b+1;c<=9;c++)
	    for(d=0;d<=9;d++)
	      for(h=0;h<=9;h++)
	        if((d+b-10==h)
	        //每个数字不相等 
	        &&b!=c&&b!=d&&b!=h
	        &&c!=d&&c!=h
	        //bcdh不能和已知的数字相等
			&&b!=0&&b!=1&&b!=8&&b!=9
		    &&c!=0&&c!=1&&c!=8&&c!=9
		    &&d!=0&&d!=1&&d!=8&&d!=9
		    &&h!=0&&h!=1&&h!=8&&h!=9)
	          printf("%d",1*1000+8*10+b);
	return 0;
}

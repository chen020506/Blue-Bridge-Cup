//  时间：2021.11.22  23点13分 
 
#include<iostream>
using namespace std;

int main ()
{
	int i,j;
	for(i=1;i<=49;i++)
		for(j=i+2;j<=49;j++)
		  if(i*i-i+j*j-j==792&&i!=10)
		  	printf("%d",i);
	return 0;
}

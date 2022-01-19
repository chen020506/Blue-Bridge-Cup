
#include<iostream>
#include<algorithm>
#include<string> 
using namespace std;
int arr[3]={1,2,3};

int main()
{
	do
	{
		cout<<arr[0]<<" "
		<<arr[1]<<" "
		<<arr[2]<<endl;
	}while(next_permutation(arr,arr+3));
}

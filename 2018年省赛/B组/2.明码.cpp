//  时间：2022.09.02  22点16分
//  思路：将十进制转化为二进制 唯一需要注意的是是负数 
//  根据翻译可知题意求的是9^9=387,420,489
#include <bits/stdc++.h>
using namespace std;
 
 void work(int x) {
     int arr[8];
     if(x < 0)  x=x+256;
     for(int i=0; i<=7; ++i) {
         arr[i] = x%2;
         x /= 2;
     }
     for(int i=7; i>=0; --i) {
         if(arr[i] == 0) printf(" ");
         else printf("*");
     }
 }
 
int main() {
     int i = 10;
     while(i--) {
         for(int j=1; j<=16; ++j) {
             int a;
             cin>>a;
             work(a);
             cin>>a;
             work(a);
             printf("\n");
         }
         printf("\n");
         printf("\n");
     }
     return 0;
 }

// 时间：2022.1.13 18点18分 
#include <stdio.h>
  
void swap(int a[], int i, int j)
{
     int t = a[i];
     a[i] = a[j];
     a[j] = t;
}
  
 int partition(int a[], int p, int r)
 {
     int i = p;
     int j = r + 1;
     int x = a[p];
     while(1){
         while(i<r && a[++i]<x);//找到左边第一个比标尺（a[p]）大的数，
		 //循环结束就是这个数a[i] 
         while(a[--j]>x);//找到右边第一个比标尺小的数 
         if(i>=j) break;//如果已经排好序，则退出就行 
         swap(a,i,j);
     }
    swap(a,p,j); // 此处可以用几个数模拟一下即可知应和j交换 
     return j;
 }
 
 void quicksort(int a[], int p, int r)
 {
     if(p<r){
         int q = partition(a,p,r);
         quicksort(a,p,q-1);
         quicksort(a,q+1,r);
     }
 }
     
 int main()
 {
     int i;
     int a[] = {5,13,6,24,2,8,19,27,6,12,1,17};
     int N = 12;
     
     quicksort(a, 0, N-1);//排序的范围 
     
     for(i=0; i<N; i++) printf("%d ", a[i]);
     printf("\n");
     
    return 0;
 }


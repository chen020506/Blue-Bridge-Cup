//  时间：2022.08.11  22点12分
//  算法：模拟
#include<bits/stdc++.h>
using namespace std;

int months[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int day,month,year;
bool check(int year,int month,int day)
{
    if(month<1||month>12) return false;
    if(day<1||day>31) return false;
    if(month!=2&&day>months[month]) return false;
    //判断是否闰年
    int flag=0;
    if((year%4==0&&year%100!=0)
        ||year%400==0)//是闰年
        flag=1;
    if(month==2&&day>months[month]+flag) return false;
    
    return true;
}

int main ()
{
    //1960年1月1日至2059年12月31日
    int a,b,c;
    scanf("%d/%d/%d",&a,&b,&c);
    for(int i=19600101;i<=20591231;i++)
    {
         year=i/10000;
         month=(i%10000)/100;
         day=i%100;    
        if(check(year,month,day))
        //年/月/日的，有采用月/日/年的，还有采用日/月/年
        if(a==year%100&&b==month&&c==day
            ||a==month&&b==day&&c==year%100
            ||a==day&&b==month&&c==year%100 )
            printf("%d-%02d-%02d\n",year,month,day);
    }
    return 0;
}


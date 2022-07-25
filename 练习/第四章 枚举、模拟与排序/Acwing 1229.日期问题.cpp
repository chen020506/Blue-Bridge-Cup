//  时间：2022.07.25  23点46分
//  来源：第八届蓝桥杯省赛C++ B组
#include<iostream>
using namespace std;
int days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool check(int year,int month,int day)
{
    if(month==0||month>12) return false;
    if(day==0||day>31) return false;
    if(month!=2){
        if(day>days[month]) return false;
    }
    else
    {
        int leap=year%100&&year%4==0||year%400==0;
        if(day>28+leap) return false;
    }
    return true;
}
int main ()
{
    int a,b,c;
    scanf("%d/%d/%d",&a,&b,&c);
    
    for(int date=19600101;date<=20591231;date++)
    {
        int year=date/10000,month=date%10000/100,day=date%100;
        if(check(year,month,day))
        {
            if(year%100==a&&month==b&&day==c|| //年/月/日
               month==a&&day==b&&year%100==c|| //月/日/年
               day==a&&month==b&&year%100==c)  //日/月/年
               printf("%d-%02d-%02d\n",year,month,day);
        }
    }
    return 0;
}
//  时间：2022.07.26  23点08分
//  算法：双指针
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
#define x first
#define y second
typedef pair<int,int> PII;

const int N=100010;
int n,d,k;
PII logs[N];
int cnt[N];
bool st[N];//记录每个帖子是不是热帖
int main ()
{
    scanf("%d%d%d",&n,&d,&k);
    for(int i=0;i<n;i++) scanf("%d%d",&logs[i].x,&logs[i].y);
    
    sort(logs,logs+n);
    
    for(int i=0,j=0;i<n;i++)
    {
        int id=logs[i].y;
        cnt[id]++;
        while(logs[i].x-logs[j].x>=d) 
        {
            cnt[logs[j].y]--;
            j++;
        }
        if(cnt[id]>=k) st[id]=true;
    }
    for(int i=0;i<=1e5;i++)
        if(st[i])
            printf("%d\n",i);
    return 0;
}
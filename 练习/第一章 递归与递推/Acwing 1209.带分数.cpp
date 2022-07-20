 //  时间：2022.07.20 20点03分
 //  算法：dfs嵌套 难度稍大
 //  第四届蓝桥杯
 #include<cstdio>
 #include<cstring>
 #include<iostream>
 using namespace std;
 
 const int N=20;
 int n,ans;
 bool st[N],backup[N];
 bool check(int a,int c)
 {
     int b=n*c-a*c;
     
     if(!a||!b||!c) return false;
     memcpy(backup,st,sizeof st);
     while(b)
     {
         int x=b%10;
         b/=10;
         if(!x||backup[x]) return false;
         backup[x]=true;
     }
     for(int i=1;i<=9;i++)
        if(!backup[i])
            return false;
    return true;
 }
 void dfs_c(int u,int a,int c)
 {
     if(u==n) return;
     if(check(a,c)) ans++;
     
     for(int i=1;i<=9;i++)
        if(!st[i])
        {
            st[i]=true;
            dfs_c(u+1,a,c*10+i);
            st[i]=false;
        }
 }
 void dfs_a(int u,int a)//u表示用了几个数 a表示a的值
 {
     if(a>=n) return;
     if(a) dfs_c(u,a,0);
     
     for(int i=1;i<=9;i++)
        if(!st[i])
        {
            st[i]=true;
            dfs_a(u+1,a*10+i);
            st[i]=false;
        }
 }
 int main ()
 {
     cin>>n;
     dfs_a(0,0);
     
     cout<<ans<<endl;
     return 0;
 }
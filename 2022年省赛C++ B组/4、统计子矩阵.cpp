#include<iostream>
using namespace std;

typedef long long LL;
const int N=510;

int n,m,k;
int s[N][N];

int main ()
{
    scanf("%d%d%d",&n,&m,&k);
    
    for(int i=1;i<=n;i++)  
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&s[i][j]);
            s[i][j]+=s[i-1][j];//列的前缀和
        }
        LL res=0;
        for(int i=1;i<=n;i++)
            for(int j=i;j<=n;j++)
                for(int l=1,r=1,sum=0;r<=m;r++)
                {
                    sum+=s[j][r]-s[i-1][r];
                    while(sum>k)
                    {
                        sum-=s[j][l]-s[i-1][l];
                        l++;
                    }
                    res+=r-l+1;
                }
        printf("%lld\n",res);
    return 0;
}

 //  第二种 暴力 只能过部分数据
// #include<iostream>
// using namespace std;
// const int N=1010;
// int n,m,w;
// int a[N][N];
// int s[N][N];

// int main ()
// {
//     cin>>n>>m>>w;
//     int res=0;
    
//     for(int i=1;i<=n;i++)
//         for(int j=1;j<=m;j++)
//             {
//                 cin>>a[i][j];
//                 s[i][j]=s[i][j-1]+s[i-1][j]-s[i-1][j-1]+a[i][j];
//             }
//     for(int i=1;i<=n;i++)
//         for(int j=1;j<=m;j++)
//             for(int k=i;k<=n;k++)   
//                 for(int l=j;l<=m;l++)
//                     if(s[k][l]-s[i-1][l]-s[k][j-1]+s[i-1][j-1]<=w)
//                         res++;
//                     else 
//                         break;
//     cout<<res<<endl;
//     return 0;
// }
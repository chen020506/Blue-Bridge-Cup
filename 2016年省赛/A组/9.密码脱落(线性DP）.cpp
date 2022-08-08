//  时间：2022.08.08  18点26分
//  算法：线性DP 区间DP
//  思路：寻找最长回文子串
#include<bits/stdc++.h>
using namespace std;

const int N=1010;
int n;
char s[N];
int f[N][N];
int main ()
{
    scanf("%s",s);
    n=strlen(s);
    
    for(int len=1;len<=n;len++)
        for(int i=0;i+len-1<n;i++)
        {
            int j=i+len-1;
            if(len==1) f[i][j]=1;
            else
            {
                f[i][j]=max(f[i+1][j],f[i][j-1]);
                if(s[i]==s[j])
                    f[i][j]=max(f[i][j],f[i+1][j-1]+2);
            }
        }
        printf("%d\n",n-f[0][n-1]);
    return 0;
}

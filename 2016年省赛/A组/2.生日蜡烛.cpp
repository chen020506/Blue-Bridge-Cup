//  时间:2022.08.07  16点16分
#include<bits/stdc++.h>
using namespace std;

int main ()
{
    for(int i=10;i<=99;i++)
        for(int j=i+1;j<=99;j++)
            if(((j-i+1)*(i+j))/2==236)
                {
                    printf("%d\n",i);
                    return 0;
                }

    return 0;
}
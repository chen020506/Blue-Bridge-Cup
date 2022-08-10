//  时间：2022.08.10  22点29分
#include<bits/stdc++.h>
using namespace std;

double g[40][40];

int main()
{
	for (int i = 1; i <= 30; i ++)
		for (int j = 1; j <= i; j ++)
			scanf("%lf", &g[i][j]);
			
	for (int i = 1; i <= 29; i ++)	
		for (int j = 1; j <= i; j ++)
		{
			g[i + 1][j]	+= g[i][j] / 2;
			g[i + 1][j + 1] += g[i][j] / 2;
		}
		
	double mmin = g[30][1], mmax = g[30][1];
	for (int i = 1; i <= 30; i ++)
	{
		mmax = max(mmax, g[30][i]);
		mmin = min(mmin, g[30][i]);
	}	
	
	printf("%f", 2086458231 / mmin * mmax);
	return 0;
}

//  时间：2022.10.17 21点31分
//  数学公式:两个互质的数所不能凑出来的数的最大值=(a-1)*(b-1)-1
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    cout << (a - 1) * (b - 1) - 1;
    return 0;
}
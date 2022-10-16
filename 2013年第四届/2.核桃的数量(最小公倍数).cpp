//  时间：2022.10.16  23点30分
#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int ab = a * b / gcd(a, b);    //求出a和b的最小公倍数
    int abc = ab * c / gcd(ab, c); //求出三个数的最小公倍数
    cout << abc;
    return 0;
}
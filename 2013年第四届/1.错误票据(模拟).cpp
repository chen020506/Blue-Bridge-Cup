// 时间：2022.10.16 23点30分
#include <bits/stdc++.h>
using namespace std;

int N, n, m;
vector<int> a;
int main()
{

    cin >> N;
    int x;
    while (N--)
    {
        getchar();
        while (cin >> x)
        {
            a.push_back(x);
        }
    }
    sort(a.begin(), a.end());

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] >= a[i - 1] + 2)
            m = a[i] - 1;
        if (a[i] == a[i - 1])
            n = a[i];
    }
    cout << m << " " << n << endl;
    return 0;
}
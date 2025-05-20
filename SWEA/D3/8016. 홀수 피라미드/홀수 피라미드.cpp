#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int testCase;
    cin >> testCase;

    for(int t = 1; t <= testCase; t++)
    {
        ll n;
        cin >> n;

        ll l = ((n - 1) * (n - 1) + 1) * 2 - 1;
        ll r = l + 4 * (n - 1);

        cout << "#" << t << " " << l << " " << r << "\n";
    }
    return 0;
}
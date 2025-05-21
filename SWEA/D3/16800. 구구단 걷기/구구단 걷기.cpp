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

        ll pos = 0;
        for(ll i = 1; i <= sqrt(n); i++)
        {
            if(n % i == 0) pos = i;
        }

        ll ans = pos + (n / pos) - 2;

        cout << "#" << t << " " << ans << "\n";
    }
    return 0;
}
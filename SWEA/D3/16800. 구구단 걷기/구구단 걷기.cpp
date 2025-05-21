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

        ll ans = 0;

        for(ll i = sqrt(n); i >= 1; i--)
        {
            if(n % i == 0)
            {
                ans = i + (n / i) - 2;
                break;
            }
        }

        cout << "#" << t << " " << ans << "\n";
    }
    return 0;
}
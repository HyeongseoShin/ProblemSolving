#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MOD 1000000007LL

ll n;

map<ll, ll> f;

ll fibo(ll x)
{
    if(x == 0) return 0;
    if(x == 1) return 1;
    if(x == 2) return 1;
    if(f.count(x)) return f[x];

    if(x % 2 == 0)
    {
        ll tmp = fibo(x / 2);
        ll tmp2 = fibo(x / 2 - 1);
        ll tmp3 = fibo(x / 2 + 1);

        return f[x] = (tmp * (tmp2 + tmp3)) % MOD;
    }
    else
    {
        ll tmp = fibo((x + 1) / 2);
        ll tmp2 = fibo((x - 1) / 2);

        return f[x] = ((tmp * tmp) % MOD + (tmp2 * tmp2) % MOD) % MOD;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    ll ans = fibo(n);

    cout << ans << "\n";
    return 0;
}
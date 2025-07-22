#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MOD 1000000007

int n;

vector<int> v;

ll ans = 0;

ll pow2[300001];


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        v.push_back(x);
    }

    sort(v.begin(), v.end());

    pow2[0] = 1;

    for(int i = 1; i < n; i++)
    {
        pow2[i] = (pow2[i-1] * 2) % MOD;
    }

    // A[i]가 가장 큰 수 일때 => iC0 + ~ + iCi => 2^i
    // A[i]가 가장 작은 수 일때 => n-(i+1)C0 + ~ + n-(i+1)Cn-(i+1) => 2^(n - (i+1))

    for(int i = 0; i < n; i++)
    {
        ll whenMax = (v[i] * pow2[i]) % MOD;
        ll whenMin = (v[i] * pow2[n - (i+1)]) % MOD;

        ans = (ans + whenMax - whenMin + MOD) % MOD;
    }

    cout << ans << "\n";

    return 0;
}
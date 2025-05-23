#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a, b;

int ans = INT_MAX;

void GetAns(ll cur, int cnt)
{
    if(cur == b)
    {
        ans = min(ans, cnt);
        return;
    }

    if(cur > b) return;
    
    GetAns(cur * 2, cnt + 1);
    GetAns(10 * cur + 1, cnt + 1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;

    GetAns(a, 0);

    if(ans == INT_MAX) cout << "-1\n";
    else cout << ans + 1 << "\n";

    return 0;
}
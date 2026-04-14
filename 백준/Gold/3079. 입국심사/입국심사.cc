#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m;

// 심사관마다 걸리는 심사 시간
vector<ll> simsa;

ll getAns(ll target)
{
    ll ret = 0LL;
    for(int i = 0; i < n; i++)
    {
        ret += (target / simsa[i]);
        if(ret >= m) break;
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;

        simsa.push_back(x);
    }

    ll st = 0LL;
    ll en = LLONG_MAX;
    ll ans = LLONG_MAX;

    while(st <= en)
    {
        ll mid = (st + en) / 2;

        ll result = getAns(mid);
        // cout << "st: " << st << " en: " << en << " mid: " << mid << " result: " << result << "\n";

        // 모든 사람 끝낼 수 있다면
        if(result >= m)
        {
            ans = min(ans, mid);
            en = mid - 1;
        }

        // 끝낼 수 없다면
        else st = mid + 1;
    }

    cout << ans << "\n";

    return 0;
}
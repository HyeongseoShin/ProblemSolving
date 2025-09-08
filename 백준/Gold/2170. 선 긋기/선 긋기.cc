#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;

ll ans = 0;

vector<pair<ll, ll>> v;
stack<pair<ll, ll>> stk;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        ll x, y;

        cin >> x >> y;

        int st = min(x, y);
        int en = max(x, y);

        v.push_back({st, en});
    }

    sort(v.begin(), v.end());

    stk.push({v[0].first, v[0].second});

    for(int i = 0; i < n; i++)
    {
        auto [st, en] = v[i];

        if(stk.empty()) stk.push({st, en});

        else
        {
            auto [topSt, topEn] = stk.top();

            if(topSt <= st && st <= topEn && en > topEn)
            {
                stk.pop();
                stk.push({topSt, en});
            }

            else if(topEn < st) stk.push({st, en});
        }
    }

    while(!stk.empty())
    {
        auto [st, en] = stk.top();

        // cout << "st: " << st << " en: " << en << "\n";
        stk.pop();

        ans += abs(st - en);
    }

    cout << ans << "\n";

    return 0;
}
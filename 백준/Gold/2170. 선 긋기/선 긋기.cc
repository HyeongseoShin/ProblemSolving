#include <bits/stdc++.h>

using namespace std;

int n;

int ans = 0;

vector<pair<int, int>> v;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int x, y;

        cin >> x >> y;

        v.push_back({x, y});
    }

    sort(v.begin(), v.end());

    int st = v[0].first;
    int en = v[0].second;

    for(int i = 1; i < n; i++)
    {
        auto [curSt, curEn] = v[i];

        if(curSt <= en)
        {
            en = max(en, curEn);
        }


        else
        {
            ans += (en - st);
            st = curSt;
            en = curEn;
        }
    }

    ans += (en - st);

    cout << ans << "\n";

    return 0;
}
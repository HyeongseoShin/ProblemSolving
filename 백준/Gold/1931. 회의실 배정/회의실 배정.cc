#include <bits/stdc++.h>

using namespace std;

// <종료 시간, 시작 시간>
vector<pair<int, int>> v;
int n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    v.resize(n);

    for(int i = 0; i < n; i++)
    {
        cin >> v[i].second >> v[i].first;
    }

    sort(v.begin(), v.end());

    int ans = 0;
    int curEnd = -1;

    for(int i = 0; i < n; i++)
    {
        if(v[i].second >= curEnd)
        {
            ans++;
            curEnd = v[i].first;
        }
    }

    cout << ans << "\n";

    return 0;
}
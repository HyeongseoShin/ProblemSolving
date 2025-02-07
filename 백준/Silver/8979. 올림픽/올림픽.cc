#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;

    cin >> n >> k;

    int targetG, targetS, targetB;

    priority_queue<pair<tuple<int, int, int>,int>> pq;

    for(int i = 0; i < n; i++)
    {
        int idx, g, s, b;
        cin >> idx >> g >> s >> b;

        pq.push({{g, s, b}, idx});

        if(idx == k)
        {
            targetG = g;
            targetS = s;
            targetB = b;
        }
    }

    int ans = 1;

    while(!pq.empty())
    {
        auto [g, s, b] = pq.top().first;

        if(targetG == g && targetS == s && targetB == b) break;
        ans++;

        pq.pop();
    }

    cout << ans << "\n";
    return 0;
}
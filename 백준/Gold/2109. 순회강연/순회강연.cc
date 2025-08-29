#include <bits/stdc++.h>

using namespace std;

int n;

vector<pair<int, int>> v;

priority_queue<int, vector<int>, greater<>> pq;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n;i++)
    {
        int p, d;
        cin >> p >> d;

        v.push_back({d, p});
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++)
    {
        auto [d, p] = v[i];
        pq.push(p);

        if((int)pq.size() > d) pq.pop();
    }

    int ans = 0;
    while(!pq.empty())
    {
        ans += pq.top();
        pq.pop();
    }

    cout << ans << "\n";

    return 0;
}
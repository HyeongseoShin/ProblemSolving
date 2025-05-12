#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int parent[100001];

int Find(int v)
{
    if(v == parent[v]) return parent[v];
    return parent[v] = Find(parent[v]);
}

void Union(int v1, int v2)
{
    v1 = Find(v1);
    v2 = Find(v2);

    if(v1 < v2) parent[v2] = v1;
    else parent[v1] = v2;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int testCase;
    cin >> testCase;

    for(int t = 1; t <= testCase; t++)
    {
        int n, m;
        cin >> n >> m;

        for(int i = 1 ; i <= n; i++)
        {
            parent[i] = i;
        }

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

        for(int i = 0; i < m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            pq.push({w, u, v});
        }

        int cnt = 0;
        ll ans = 0;

        while(!pq.empty() && cnt < m - 1)
        {
            auto [w, u, v] = pq.top();
            pq.pop();

            if(Find(u) != Find(v))
            {
                Union(u, v);
                cnt++;
                ans += (ll)w;
            }
        }

        cout << "#" << t << " " << ans << "\n";
    }

    return 0;
}
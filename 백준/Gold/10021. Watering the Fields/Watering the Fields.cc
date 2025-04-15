#include <bits/stdc++.h>

using namespace std;

int n, c;

vector<pair<int, int>> edges;
vector<pair<int, int>> fields;

int parent[2005];

priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

int Find(int v)
{
    if(parent[v] == v)
    {
        return parent[v];
    }
    
    return parent[v] = Find(parent[v]);
}

void Union(int v1, int v2)
{
    v1 = Find(v1);
    v2 = Find(v2);

    if(v1 < v2) parent[v2] = v1;
    else parent[v1] = v2;
}

int GetDist(int x1, int x2, int y1, int y2)
{
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> c;

    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;

        parent[i] = i;
        fields.push_back({x, y});
    }

    for(int i = 0; i < n; i++)
    {
        auto [r1, c1] = fields[i];

        for(int j = i + 1; j < n; j++)
        {
            auto [r2, c2] = fields[j];

            int dist = GetDist(r1, r2, c1, c2);
            if(dist < c) continue;

            pq.push({dist, i, j});
        }
    }

    int cnt = 0;
    int ans = 0;

    while(cnt < n - 1 && !pq.empty())
    {
        auto [w, u, v] = pq.top();
        pq.pop();

        
        if(Find(u) != Find(v))
        {
            Union(u, v);
            cnt++;
            ans += w;
        }
    }

    if(cnt == n - 1) cout << ans << "\n";
    else cout << "-1\n";
    
    return 0;
}
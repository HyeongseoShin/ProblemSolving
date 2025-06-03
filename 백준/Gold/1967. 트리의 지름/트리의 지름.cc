#include <bits/stdc++.h>

using namespace std;

int n;

vector<pair<int, int>> adj[10001];

int ans = 0;

int dist[100001];

void BFS(int x)
{
    queue<int> q;
    q.push(x);

    
    fill(dist, dist + n + 1, -1);
    dist[x] = 0;

    while(!q.empty())
    {
        auto cur = q.front();
        q.pop();

        for(auto [nxtW, nxtV] : adj[cur])
        {
            if(dist[nxtV] != -1) continue;

            dist[nxtV] = dist[cur] + nxtW;
            q.push(nxtV);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    BFS(1);

    int maxIdx = 1;
    for(int i = 1; i <= n; i++)
    {
        if(dist[maxIdx] < dist[i]) maxIdx = i;
    }
    
    BFS(maxIdx);

    for(int i = 1; i <= n; i++)
    {
        ans = max(ans, dist[i]);
    }

    cout << ans << "\n";

    return 0;
}
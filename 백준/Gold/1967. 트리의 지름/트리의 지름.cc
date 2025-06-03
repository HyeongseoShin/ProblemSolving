#include <bits/stdc++.h>

using namespace std;

int n;

vector<pair<int, int>> adj[10001];

int ans = 0;

void BFS(int x)
{
    queue<int> q;
    q.push(x);

    int dist[100001];
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

    for(int i = 1; i <= n; i++)
    {
        ans = max(ans, dist[i]);
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

    for(int i = 1; i <= n; i++)
    {
        BFS(i);
    }

    cout << ans << "\n";

    return 0;
}
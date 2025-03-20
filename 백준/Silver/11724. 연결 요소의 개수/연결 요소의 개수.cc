#include <bits/stdc++.h>

using namespace std;

int n, m;

vector<int> adj[1005];

bool vis[1005];

int ans = 0;

void DFS(int x)
{
    vis[x] = true;

    for(int nxt : adj[x])
    {
        if(vis[nxt]) continue;

        DFS(nxt);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        int u, v;

        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 1; i <= n; i++)
    {
        if(vis[i]) continue;

        DFS(i);
        ans++;
    }

    cout << ans << "\n";


    return 0;
}
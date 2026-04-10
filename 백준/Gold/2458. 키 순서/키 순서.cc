// https://www.acmicpc.net/problem/2458

#include <bits/stdc++.h>

using namespace std;

int n, m;

vector<int> adj[501];

int cnt[501];

int ans = 0;

bool vis[501];

void dfs(int st, int idx)
{
    if(vis[idx]) return;

    vis[idx] = true;
    cnt[idx]++;
    cnt[st]++;

    for(int nxt : adj[idx])
    {
        dfs(st, nxt);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
    }

    for(int i = 1; i <= n; i++)
    {
        memset(vis, false, sizeof(vis));
        dfs(i, i);
    }

    for(int i = 1; i <= n; i++)
    {
        if(cnt[i] == n + 1) ans++;
    }
    
    cout << ans << "\n";

    return 0;
}
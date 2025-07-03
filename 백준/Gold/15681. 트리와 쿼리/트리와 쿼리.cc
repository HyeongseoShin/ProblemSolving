#include <bits/stdc++.h>

using namespace std;

#define MAX 100001
int n, r, q;

int dp[MAX]; // dp[i]: i정점을 루트로 하는 서브트리에 속한 정점 수

bool vis[MAX];

vector<int> adj[MAX];

void DFS(int cur, int parent)
{
    vis[cur] = true;

    for(auto nxt : adj[cur])
    {
        if(vis[nxt]) continue;

        DFS(nxt, cur);
    }

    if(parent != -1)
    {
        dp[parent] += dp[cur];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> r >> q;

    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    fill(dp, dp + MAX, 1);

    DFS(r, -1);

    while(q--)
    {
        int x;
        cin >> x;

        cout << dp[x] << "\n";
    }

    return 0;
}
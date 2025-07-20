#include <bits/stdc++.h>

using namespace std;

#define MAX 1000001
int n;

vector<int> adj[MAX];

// dp[i][0] : i가 얼리어답터가 아닐 때 최소 얼리어답터 수
// dp[i][1] : i가 얼리어답터일 때 최소 얼리어답터 수
int dp[MAX][2];

bool vis[MAX];

void DFS(int prev, int cur)
{
    vis[cur] = true;

    for(auto nxt : adj[cur])
    {
        if(!vis[nxt]) DFS(cur, nxt);
    }

    dp[cur][1]++;
    dp[prev][0] += dp[cur][1];
    dp[prev][1] += min(dp[cur][0], dp[cur][1]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFS(0, 1);

    cout << min(dp[1][0], dp[1][1]) << "\n";

    return 0;
}
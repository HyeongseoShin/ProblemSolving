#include <bits/stdc++.h>

using namespace std;

int n;

int people[10005];

vector<int> adj[10005];

// dp[i][0] : i가 우수마을이 아닐 때 최대 주민 수
// dp[i][1] : i가 우수마을일 때 최대 주민 수
int dp[10005][2];

bool vis[10005];

void dfs(int cur)
{
    vis[cur] = true;
    dp[cur][1] = people[cur];

    for(int nxt : adj[cur])
    {
        if(vis[nxt]) continue;

        dfs(nxt);

        dp[cur][0] += max(dp[nxt][0], dp[nxt][1]);
        dp[cur][1] += dp[nxt][0];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        cin >> people[i];
    }

    for(int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1); // 임의의 노드를 루트로

    int ans = max(dp[1][0], dp[1][1]);

    cout << ans << "\n";

    return 0;
}
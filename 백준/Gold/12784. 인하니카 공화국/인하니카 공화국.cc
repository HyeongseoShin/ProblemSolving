#include <bits/stdc++.h>

using namespace std;

int t, n, m;

vector<pair<int, int>> dynamite[1005];

int dp[1005];
bool vis[1005];

int dfs(int cur)
{
    // 리프 노드일 때
    if(dynamite[cur].size() == 1 && cur != 1) return INT_MAX;

    vis[cur] = true;

    int sum = 0;
    for(auto [cnt, nxt] : dynamite[cur])
    {
        if(vis[nxt]) continue;

        sum += min(dfs(nxt), cnt);
    }

    return sum;
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> m;

        for(int i = 0; i <= n; i++)
        {
            vis[i] = false;
            dynamite[i].clear();
        }

        for(int i = 0; i < m; i++)
        {
            int a, b, d;
            cin >> a >> b >> d;

            dynamite[a].push_back({d, b});
            dynamite[b].push_back({d, a});
        }

        cout << dfs(1) << "\n";
    }

    return 0;
}
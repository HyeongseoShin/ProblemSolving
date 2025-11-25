#include <bits/stdc++.h>

using namespace std;

int t, n, m;

vector<pair<int, int>> dynamite[1005];

int dp[1005];
bool vis[1005];

int dfs(int cur)
{
    vis[cur] = true;

    int sum = 0;
    for(auto [cnt, nxt] : dynamite[cur])
    {
        if(vis[nxt]) continue;

        int nxtVal = dfs(nxt);

        nxtVal = min(nxtVal, cnt);

        sum += nxtVal;
    }

    return (sum == 0 ? INT_MAX : sum);
    
    
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

        cout << (n == 1 ? 0 : dfs(1)) << "\n";
    }

    return 0;
}
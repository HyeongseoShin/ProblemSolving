#include <bits/stdc++.h>

using namespace std;

int n, m, k;

int candy[30001];

vector<int> adj[30001];

vector<pair<int,int>> amount; // <사탕 수, 뺏은 사람 수>

bool vis[30001];

// dp[i][j] : 현재 i번째까지 봤고, j 사람의 사탕을 뺏었을 때 최대 사탕 수
int dp[30001][3001];

// BFS 순회하며 amount 채우기
void BFS(int v)
{
    vis[v] = true;
    
    queue<int> q;
    q.push(v);

    int sum = candy[v]; // 뺏은 사탕 수
    int cnt = 1; // 사탕 뺏긴 사람 수

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        for(int nxt : adj[cur])
        {
            if(vis[nxt]) continue;

            q.push(nxt);
            vis[nxt] = true;
            sum += candy[nxt];
            cnt++;
        }
    }

    amount.push_back({sum, cnt});
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    k = min(k, 3000);

    for(int i = 1; i <= n; i++) cin >> candy[i];
    
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 뺏을 수 있는 사탕, 사람 수 구하기
    for(int i = 1; i <= n; i++)
    {
        if(!vis[i]) BFS(i);
    }


    // DP 진행 (냅색)
    int amountLen = (int)amount.size();
    auto [c, p] = amount[0];
    dp[0][p] = c;

    for(int i = 1; i < amountLen; i++)
    {
        auto [c, p] = amount[i];

        for(int j = 1; j < k; j++)
        {
            if(p <= j)
            {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j - p] + c);
            }

            else dp[i][j] = dp[i-1][j];
        }
    }

    int ans = 0;

    for(int i = 0; i < k; i++)
    {
        if(ans < dp[amountLen - 1][i])
        {
            ans = max(ans, dp[amountLen - 1][i]);
        }
    }

    cout << ans << "\n";

    return 0;
}
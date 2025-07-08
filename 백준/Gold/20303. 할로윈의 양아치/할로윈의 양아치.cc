#include <bits/stdc++.h>

using namespace std;

int n, m, k;

int candy[30001];

vector<int> adj[30001];

vector<pair<int,int>> amount; // <사탕 수, 뺏은 사람 수>

bool vis[30001];

// dp[i] : i명의 사탕을 뺏었을 때 최대 사탕 수
int dp[3001];

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

    for(int i = 0; i < (int)amount.size(); i++)
    {
        auto [c, p] = amount[i];
        for(int j = k - 1; j >= p; j--)
        {
            dp[j] = max(dp[j], dp[j-p] + c);
        }
    }

    cout << *max_element(dp, dp + k) << "\n";

    return 0;
}
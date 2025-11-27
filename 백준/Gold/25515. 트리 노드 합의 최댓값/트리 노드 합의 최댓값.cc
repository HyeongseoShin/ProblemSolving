#include <bits/stdc++.h>

using namespace std;

#define MAX 100001

typedef long long ll;

int n;

vector<int> adj[MAX];

ll weights[MAX];

bool vis[MAX];

// dfs(cur) : cur - 자식까지 가는데 방문 가능한 정수의 최대 합
ll dfs(int cur)
{
    vis[cur] = true;

    ll sum = weights[cur];

    for(auto nxt : adj[cur])
    {
        if(vis[nxt]) continue;
        sum = max(sum, sum + dfs(nxt));
    }

    return sum;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n - 1; i++)
    {
        int p, c;
        cin >> p >> c;

        adj[p].push_back(c);
        adj[c].push_back(p);
    }

    for(int i = 0; i < n; i++) cin >> weights[i];

    cout << dfs(0) << "\n";

    return 0;
}
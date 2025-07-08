#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int candy[30001];
vector<int> adj[30001];
bool vis[30001];

vector<pair<int, int>> amount;  // {사탕 합, 인원 수}

void bfs(int start) {
    queue<int> q;
    q.push(start);
    vis[start] = true;

    int cnt = 1;
    int totalCandy = candy[start];

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int nxt : adj[cur]) {
            if (!vis[nxt]) {
                vis[nxt] = true;
                totalCandy += candy[nxt];
                cnt++;
                q.push(nxt);
            }
        }
    }

    amount.push_back({totalCandy, cnt});
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) cin >> candy[i];

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 그룹 단위로 묶기
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) bfs(i);
    }

    // 1차원 DP 배열로 냅색 문제 해결
    vector<int> dp(k, 0);  // dp[j] = j명의 아이를 뺏었을 때 최대 사탕 수

    for (auto [c, p] : amount) {
        for (int j = k - 1; j >= p; j--) {
            dp[j] = max(dp[j], dp[j - p] + c);
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << "\n";
    return 0;
}
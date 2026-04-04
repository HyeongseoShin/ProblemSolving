#include <bits/stdc++.h>

using namespace std;

#define MAX 3000001 // 200 * 100만보다 더 큰 수

// 집하장, 집하장 간 경로
int n, m;

vector<pair<int, int>> adj[201];

int ans[201][201];

// 다익스트라로 각 구간
void calcPath(int st)
{
    int dist[201]; // 최소 거리
    int pre[201]; // 최소 거리를 위한 경로

    for(int i = 1; i <= n; i++) dist[i] = MAX;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // <최단거리, 다음 칸>
    
    pre[st] = 0;
    dist[st] = 0;
    pq.push({dist[st], st});

    while(!pq.empty())
    {
        auto [curDist, cur] = pq.top();
        pq.pop();

        if(dist[cur] < curDist) continue;

        for(auto [nDist, nxt] : adj[cur])
        {
            if(dist[nxt] < dist[cur] + nDist) continue;

            pre[nxt] = cur;
            dist[nxt] = dist[cur] + nDist;
            pq.push({dist[nxt], nxt});
        }
    }

    for(int i = 1; i <= n; i++)
    {
        if(st == i) continue;

        int nxt = i;
        while(pre[nxt] != st)
        {
            nxt = pre[nxt];
        }

        ans[st][i] = nxt;
        //cout << "st: " << st << " en: " << i << " ans: " << ans[st][i] << "\n";
    }

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    for(int i = 1; i <= n; i++) calcPath(i);

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i == j) cout << "- ";
            else cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
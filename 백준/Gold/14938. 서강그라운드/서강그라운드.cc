#include <bits/stdc++.h>

using namespace std;

// 정점 개수, 수색 범위, 길의 개수
int n, m, r;

// 각 지점별 아이템 개수
int itemCnt[101];

// <간선, 도착점>
vector<pair<int, int>> adj[101];

int ans = 0;

int Dijkstra(int x)
{
    int dist[101];
    fill(dist, dist + 101, INT_MAX);
    dist[x] = 0;

    priority_queue<pair<int, int>> pq;
    pq.push({dist[x], x});

    while(!pq.empty())
    {
        auto [curW, curV] = pq.top();
        pq.pop();

        for(auto [nxtW, nxtV] : adj[curV])
        {
            if(dist[nxtV] > dist[curV] + nxtW)
            {
                dist[nxtV] = dist[curV] + nxtW;
                pq.push({dist[nxtV], nxtV});

            }
        }
    }

    int ret = 0;
    for(int i = 1; i <= n; i++)
    {
        // cout << dist[i] << " ";
        if(dist[i] <= m) ret += itemCnt[i];
    }
    // cout << "\n";
    
    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> r;

    for(int i = 1; i <= n; i++)
    {
        cin >> itemCnt[i];
    }

    for(int i = 0; i < r; i++)
    {
        int a, b, l;
        cin >> a >> b >> l;

        adj[a].push_back({l, b});
        adj[b].push_back({l, a});
    }

    // 각 지점에서 Dijkstra
    for(int i = 1; i <= n; i++)
    {
        ans = max(ans, Dijkstra(i));
        // cout << BFS(i) << "\n";
        // cout << "i: " << i << " 결과: " << BFS(i) << "\n";
        // cout << "=======================\n";
    }

    cout << ans << "\n";
    
    return 0;
}
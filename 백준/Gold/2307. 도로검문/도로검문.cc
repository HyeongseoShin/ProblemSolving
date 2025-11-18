#include <bits/stdc++.h>

using namespace std;

int n, m;

vector<pair<int, int>> adj[5001];
int dist[1001];
int pre[1001];

vector<pair<int, int>> checkEdges; // 최단 경로에 사용한 Edge 모음

int ans = -1;

void Dijkstra()
{
    // <현재까지 거리, 정점>
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    fill(dist, dist + n + 1, INT_MAX);
    dist[1] = 0;

    memset(pre, -1, sizeof(pre));
    pre[1] = 0;

    pq.push({dist[1], 1});

    while(!pq.empty())
    {
        auto [curDist, cur] = pq.top();
        pq.pop();

        if(curDist > dist[cur]) continue;

        for(auto [nxtDist, nxt] : adj[cur])
        {
            if(dist[nxt] > curDist + nxtDist)
            {
                dist[nxt] = curDist + nxtDist;
                pq.push({dist[nxt], nxt});
                pre[nxt] = cur;
            }
        }
    }
}

void DijkstraWithCheck(int from, int to)
{
    // <현재까지 거리, 정점>
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    int tmpDist[1001];
    fill(tmpDist, tmpDist + n + 1, INT_MAX);
    tmpDist[1] = 0;

    pq.push({tmpDist[1], 1});

    while(!pq.empty())
    {
        auto [curDist, cur] = pq.top();
        pq.pop();

        if(curDist > tmpDist[cur]) continue;

        for(auto [nxtDist, nxt] : adj[cur])
        {
            // 검문 중이라 패스
            if((cur == from && nxt == to) || (cur == to && nxt == from)) continue;

            if(tmpDist[nxt] > curDist + nxtDist)
            {
                tmpDist[nxt] = curDist + nxtDist;
                pq.push({tmpDist[nxt], nxt});
                pre[nxt] = cur;
            }
        }
    }

    if(tmpDist[n] == INT_MAX) ans = INT_MAX;
    else ans = max(ans, tmpDist[n] - dist[n]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        int a, b, t;
        cin >> a >> b >> t;

        adj[a].push_back({t, b});
        adj[b].push_back({t, a});
    }

    Dijkstra();

    // 최단 경로에 사용한 Edges 구해서 저장
    int nxt = pre[n];
    checkEdges.push_back({n, pre[n]});
    while(pre[nxt] != -1)
    {
        checkEdges.push_back({nxt, pre[nxt]});
        nxt = pre[nxt];        
    }

    for(auto [a, b] : checkEdges)
    {
        DijkstraWithCheck(a, b);
    }

    if(ans == INT_MAX) ans = -1;

    cout << ans << "\n";

    return 0;
}
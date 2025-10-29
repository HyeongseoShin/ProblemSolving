#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define MAX 100001

int n, m, k;

vector<pair<ll, int>> adj[MAX];

priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq; // 다익스트라 우선순위 큐
ll dist[MAX]; // 면접장에서 출발했을 때 각 정점까지 갈 수 있는 최단 거리

void Dijkstra()
{
    while(!pq.empty())
    {
        auto [curDist, cur] = pq.top();
        pq.pop();

        if(dist[cur] < curDist) continue;

        for(auto [nxtDist, nxt] : adj[cur])
        {
            if(dist[nxt] > curDist + nxtDist)
            {
                dist[nxt] = curDist + nxtDist;
                pq.push({dist[nxt], nxt});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    for(int i = 0; i < m; i++)
    {
        int u, v;
        ll c;

        cin >> u >> v >> c;

        // 역방향 그래프를 생성해야 면접장 -> 도시까지의 최단 거리 구할 수 있음
        adj[v].push_back({c, u});
    }

    fill(dist, dist + n + 1, LLONG_MAX); // 최단거리 배열 초기화

    // 면접 장소 저장
    for(int i = 0; i < k; i++)
    {
        int x;
        cin >> x;

        dist[x] = 0;
        pq.push({dist[x], x});
    }

    Dijkstra();

    ll ans = 0;
    ll ansIdx = 0;

    for(int i = 1; i <= n; i++)
    {
        if(ans < dist[i])
        {
            ansIdx = i;
            ans = dist[i];
        }
    }

    cout << ansIdx << "\n";
    cout << ans << "\n";

    return 0;
}
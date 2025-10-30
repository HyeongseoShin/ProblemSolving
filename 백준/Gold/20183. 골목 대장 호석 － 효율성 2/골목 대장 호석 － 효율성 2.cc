#include <bits/stdc++.h>

using namespace std;

#define MAX 100001
typedef long long ll;

int n, m, st, en;
ll money;

vector<pair<ll, int>> adj[MAX];

ll dist[MAX];
ll ans = LLONG_MAX;

// <거리, 경로 중 수금 최댓값, 위치>
void Dijkstra()
{
    priority_queue<tuple<ll, ll, int>, vector<tuple<ll, ll, int>>, greater<>> pq;
    dist[st] = 0LL;
    pq.push({dist[st], 0LL, st});

    while(!pq.empty())
    {
        auto [curDist, curMoney, cur]  = pq.top();
        pq.pop();

        // cout << "cur: " << cur << " curDist: " << curDist << " curMoney: " << curMoney << "\n";

        if(cur == en)
        {
            ans = min(ans, curMoney);
            continue;
        }

        if(dist[cur] < curDist) continue;

        for(auto [nxtDist, nxt] : adj[cur])
        {
            if(dist[nxt] > curDist + nxtDist && curDist + nxtDist <= money)
            {
                dist[nxt] = curDist + nxtDist;
                ll nxtMoney = max(nxtDist, curMoney);

                pq.push({dist[nxt], nxtMoney, nxt});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> st >> en >> money;

    for(int i = 0; i < m; i++)
    {
        int from, to;
        ll c;

        cin >> from >> to >> c;

        adj[from].push_back({c, to});
        adj[to].push_back({c, from});
    }

    fill(dist, dist + n + 1, LLONG_MAX);

    Dijkstra();

    if(dist[en] == LLONG_MAX) ans = -1;

    cout << ans << "\n";

    return 0;
}
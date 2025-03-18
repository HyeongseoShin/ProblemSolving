#include <bits/stdc++.h>

using namespace std;

#define MAX 1000000

int n, p, k;

vector<pair<int, int>> adj[1005];

int dst[1005];

bool Dijkstra(int x)
{
    priority_queue<pair<int, int>> pq;

    dst[1] = 0;

    pq.push({dst[1], 1});

    while(!pq.empty())
    {
        int now = pq.top().second;
        int cost = -pq.top().first;

        pq.pop();

        if(dst[now] < cost) continue;

        for(auto i : adj[now])
        {
            int nxt = i.first;
            int nxtCost = cost + (i.second > x);
            if(nxtCost < dst[nxt])
            {
                dst[nxt] = nxtCost;
                pq.push({-nxtCost, nxt});
            }
        }
    }

    return dst[n] <= k;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> p >> k;

    int st = 0;
    int en = 0;

    for(int i = 0; i < p; i++)
    {
        int u, v, w;

        cin >> u >> v >> w;

        en = max(en, w);

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int mid;
    int ans = -1;

    while(st <= en)
    {
        mid = (st + en) / 2;
        fill(dst, dst + 1005, MAX);
        
        if(Dijkstra(mid)) 
        {
            ans = mid;
            en = mid - 1;
        }
        
        else st = mid + 1;   
    }
    
    cout << ans << "\n";

    return 0;
}
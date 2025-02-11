// https://www.acmicpc.net/problem/5972

// 다익스트라
#include <bits/stdc++.h>

using namespace std;

int n, m;

vector<pair<int, int>> adj[50010];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int dst[50010];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    fill(dst, dst + n + 1, 1e9 + 10);

    while(m--)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    dst[1] = 0;
    pq.push({dst[1], 1});

    while(!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();

        int curW = cur.first;
        int curV = cur.second;

        if(dst[curV] != curW) continue;

        for(auto nxt : adj[curV])
        {
            int nxtW = nxt.first;
            int nxtV = nxt.second;

            if(dst[nxtV] <= dst[curV] + nxtW) continue;

            dst[nxtV] = dst[curV] + nxtW;
            pq.push({dst[nxtV], nxtV});
        }
    }

    cout << dst[n] << "\n";

    return 0;
}
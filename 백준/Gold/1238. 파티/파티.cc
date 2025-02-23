// https://www.acmicpc.net/problem/1238
// 다익스트라
#include <bits/stdc++.h>

using namespace std;

int n, m, x;

vector<pair<int, int>> adj[1005];

int dstTo [1005];
int dstFrom [1005];

int ansTo[1005];

void BFS(int now)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    
    if(now == x)
    {
        dstFrom[now] = 0;
        pq.push({now, dstFrom[now]});

        while(!pq.empty())
        {
            auto [curV, curW] = pq.top();
            pq.pop();

            if(dstFrom[curV] != curW) continue;

            for(auto [nV, nW] : adj[curV])
            {
                if(dstFrom[nV] > dstFrom[curV] + nW)
                {
                    dstFrom[nV] = dstFrom[curV] + nW;
                    pq.push({nV, dstFrom[nV]});
                }
            }
        }
    }

    else
    {
        dstTo[now] = 0;
        pq.push({now, dstTo[now]});

        while(!pq.empty())
        {
            auto [curV, curW] = pq.top();
            pq.pop();

            if(dstTo[curV] != curW) continue;

            for(auto [nV, nW] : adj[curV])
            {
                if(dstTo[nV] > dstTo[curV] + nW)
                {
                    dstTo[nV] = dstTo[curV] + nW;
                    pq.push({nV, dstTo[nV]});
                }
            }
        }

        ansTo[now] = dstTo[x];
    }

    
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> x;

    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
    }

    for(int i = 1; i <= n; i++)
    {
        if(i == x)
        {
            fill(dstFrom, dstFrom + n + 1, INT_MAX);
        }
        
        else fill(dstTo, dstTo + n + 1, INT_MAX);

        BFS(i);
        
        
    }

    int ans = -1;
    for(int i = 1; i <= n; i++)
    {
        if(ansTo[i] + dstFrom[i] > ans)
        {
            ans = ansTo[i] + dstFrom[i];
        }

        // cout << dstFrom[i] << " ";
        // cout << ansTo[i] << "\n";
    }

    cout << ans << "\n";

    return 0;
}
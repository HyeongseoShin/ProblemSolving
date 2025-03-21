#include <bits/stdc++.h>

using namespace std;

int n, m, k;

// <소요 시간, 도착 시간>
// <단 방향>
vector<pair<int, int>> adj[1005];

priority_queue<int> dst[1005];

void Dijkstra()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dst[1].push(0);

    pq.push({dst[1].top(), 1});

    while(!pq.empty())
    {
        auto [curW, curV] = pq.top();
        pq.pop();

        for(auto [nW, nV] : adj[curV])
        {
            if(dst[nV].size() < k)
            {
                dst[nV].push(curW + nW);
                pq.push({curW + nW, nV});
            }

            else if(dst[nV].size() >= k && dst[nV].top() > curW + nW)
            {
                dst[nV].push(curW + nW);
                dst[nV].pop();
                pq.push({curW + nW, nV});
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
        int a, b, c;

        cin >> a >> b >> c;

        adj[a].push_back({c, b});
    }

    Dijkstra();

    for(int i = 1; i <= n; i++)
    {
        if(dst[i].size() < k) cout << "-1\n";
        else cout << dst[i].top() << "\n";

        // cout << dst[i].size() << " ";
    }
    cout << "\n";



    return 0;
}
#include <bits/stdc++.h>

using namespace std;

void BFS(int now, vector<pair<int, int>>* tmpAdj, int* arr)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    
    arr[now] = 0;
    pq.push({now, arr[now]});

    while(!pq.empty())
    {
        auto [curV, curW] = pq.top();
        pq.pop();

        if(arr[curV] != curW) continue;

        for(auto [nV, nW] : tmpAdj[curV])
        {
            if(arr[nV] > arr[curV] + nW)
            {
                arr[nV] = arr[curV] + nW;
                pq.push({nV, arr[nV]});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<pair<int, int>> adj[1005];
    vector<pair<int, int>> reverseAdj[1005];

    int dstTo [1005];
    int dstFrom [1005];

    int n, m, x;

    cin >> n >> m >> x;

    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        reverseAdj[v].push_back({u, w});
    }

    fill(dstTo, dstTo + n + 1, INT_MAX);
    fill(dstFrom, dstFrom + n + 1, INT_MAX);

    BFS(x, adj, dstFrom); // 정방향
    BFS(x, reverseAdj, dstTo); // 역방향

    int ans = -1;
    for(int i = 1; i <= n; i++)
    {
        if(dstTo[i] + dstFrom[i] > ans)
        {
            ans = dstTo[i] + dstFrom[i];
        }
    }

    cout << ans << "\n";

    return 0;
}
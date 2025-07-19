#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 10;
int n, m, st, en;

vector<pair<int,int>> adj[2000];
int d[2000]; // 최단거리 배열
int pre[2000]; // 경로 저장 배열

void Dijkstra()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>,  greater<pair<int, int>>> pq;
    pq.push({d[st], st});

    while(!pq.empty())
    {
        int curW = pq.top().first;
        int curV = pq.top().second;

        pq.pop();

        if(d[curV] != curW) continue;

        for(auto nxt: adj[curV])
        {
            int nxtW = nxt.first;
            int nxtV = nxt.second;

            if(d[nxtV] <= d[curV] + nxtW) continue;
            
            d[nxtV] = d[curV] + nxtW;
            pre[nxtV] = curV;
            pq.push({d[nxtV], nxtV});
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    while(m--)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({w, v});
    }

    cin >> st >> en;

    fill(d, d + n + 1, INF);
    d[st] = 0;

    Dijkstra();  

    cout << d[en] << "\n";

    int cur = en;
    vector<int> path;

    while(cur != 0)
    {
        path.push_back(cur);
        cur = pre[cur];
    }

    cout << path.size() << "\n";

    reverse(path.begin(), path.end());

    for(auto it = path.begin(); it != path.end(); it++)
    {
        cout << *it << " ";
    }
    cout << "\n";

    return 0;
}
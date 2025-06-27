#include <bits/stdc++.h>

using namespace std;

int t, n, k, w;

int d[1001];

int dist[1001];

vector<int> adj[1001];

void BFS(int x)
{
    dist[x] = d[x];

    queue<int> q;
    q.push(x);

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        for(auto nxt : adj[cur])
        {
            if(dist[nxt] < dist[cur] + d[nxt])
            {
                dist[nxt] = dist[cur] + d[nxt];
                q.push(nxt);
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> k;

        for(int i = 1; i <= n; i++)
        {
            cin >> d[i];
        }

        for(int i = 1; i <= 1000; i++)
        {
            adj[i].clear();
        }

        while(k--)
        {
            int u, v;
            cin >> u >> v;

            adj[u].push_back(v);
        }

        cin >> w;


        fill(dist, dist + 1001, 0);

        for(int i = 1; i <= n; i++)
        {
            if(dist[i] == 0)
            {
                BFS(i);
            }
        }

        cout << dist[w] << "\n";
    }
    
    return 0;
}
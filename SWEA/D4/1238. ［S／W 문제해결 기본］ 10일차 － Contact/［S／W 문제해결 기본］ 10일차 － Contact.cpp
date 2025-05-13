#include <bits/stdc++.h>

using namespace std;

int n, st;

vector<int> adj[105];

int dist[105];

void BFS(int x)
{
    queue<int> q;
    q.push(x);
    dist[x] = 0;

    while(!q.empty())
    {
        auto cur = q.front();
        q.pop();

        for(auto nxt : adj[cur])
        {
            if(dist[nxt] != INT_MAX) continue;
            dist[nxt] = dist[cur] + 1;

            q.push(nxt);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int t = 1; t <= 10; t++)
    {
        cin >> n >> st;

        int from, to;

        for(int i = 1; i < 105; i++)
        {
            adj[i].clear();
        }
        for(int i = 0; i < n; i++)
        {
            int x;
            cin >> x;

            if(i % 2 == 0) from = x;
            else
            {
                to = x;
                adj[from].push_back(to);
            }
        }

        for(int i = 1; i < 105; i++)
        {
            dist[i] = INT_MAX;
        }

        BFS(st);

        int ans = 0;
        int ansIdx = 1;
        for(int i = 100; i >= 1; i--)
        {
            if(dist[i] == INT_MAX) continue;

            if(ans < dist[i])
            {
                ans = dist[i];
                ansIdx = i;
            }

        }
        cout << "#" << t << " " << ansIdx << "\n";
    }
    return 0;
}
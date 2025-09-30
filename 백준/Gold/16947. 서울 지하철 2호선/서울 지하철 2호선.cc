#include <bits/stdc++.h>

using namespace std;

int n;

vector<int> adj[3001];

int dist[3001];

bool isFinished = false;

void DFS(int cur, int past, int curDist)
{
    if(dist[cur] != -1)
    {
        cout << dist[cur] << " ";
        isFinished = true;

        return;
    }

    dist[cur] = curDist + 1;

    for(auto nxt : adj[cur])
    {
        if(nxt == past) continue;

        DFS(nxt, cur, dist[cur]);

        if(isFinished) return;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int from, to;
        cin >> from >> to;

        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    for(int i = 1; i <= n; i++)
    {
        memset(dist, -1, sizeof(dist));
        isFinished = false;
        DFS(i, 0, -1);
    }
    cout << "\n";

    return 0;
}
// https://www.acmicpc.net/problem/10159

#include <bits/stdc++.h>

using namespace std;

int n, m;

vector<int> adjBigger[101];
vector<int> adjSmaller[101];

int cnt[101];

bool vis[101];

void BFS(int x, vector<int> adj[], bool isBigger)
{
    queue<int> q;
    q.push(x);

    vis[x] = true;
    if(isBigger) cnt[x]++;

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        for(auto nxt : adj[cur])
        {
            if(vis[nxt]) continue;

            vis[nxt] = true;
            cnt[x]++;
            q.push(nxt);
        }
    }
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < m ;i++)
    {
        int x, y;
        cin >> x >> y;

        adjBigger[x].push_back(y);
        adjSmaller[y].push_back(x);
    }
    
    for(int i = 1; i <= n; i++)
    {
        fill(vis, vis + n + 1, false);
        BFS(i, adjBigger, true);
    }

    for(int i = 1; i <= n; i++)
    {
        fill(vis, vis + n + 1, false);
        BFS(i, adjSmaller, false);
    }

    for(int i = 1; i <= n; i++)
    {
        cout << n - cnt[i] << "\n";
    }

    return 0;
}
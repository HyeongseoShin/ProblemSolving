#include <bits/stdc++.h>

using namespace std;

vector<int> adj[11];

int n, m;

int ans = 0;

bool vis[11];

void DFS(int v, int depth)
{
    ans = max(ans, depth);
    
    for(auto nxt : adj[v])
    {
        // cout << "v: " << v << " nxt: " << nxt << " depth: " << depth << "\n";
        if(vis[nxt]) continue;
        
        vis[nxt] = true;
        DFS(nxt, depth + 1);
        vis[nxt] = false;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int testCase;
    cin >> testCase;
    
    for(int t = 1; t <= testCase; t++)
    {        
        cin >> n >> m;

        for(int i = 0; i < 11; i++)
        {
            adj[i].clear();
        }
        
        for(int i = 0; i < m; i++)
        {
            int from, to;
            cin >> from >> to;
            
            adj[from].push_back(to);
            adj[to].push_back(from);
        }
        
        ans = 0;
        for(int i = 1; i <= n; i++)
        {
            fill(vis, vis + n + 1, false);
            vis[i] = true;
            DFS(i, 1);
        }
        
        cout << "#" << t << " " << ans << "\n";
        // cout << "\n==========\n";
    }
    return 0;
}
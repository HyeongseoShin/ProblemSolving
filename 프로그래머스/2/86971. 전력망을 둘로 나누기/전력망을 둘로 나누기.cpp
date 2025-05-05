#include <bits/stdc++.h>

using namespace std;

set<int> adj[101];

bool vis[101];

vector<int> amount;

int ans = 100;

int cur = 0;

void BFS(int idx)
{    
    int cnt = 0;
    
    queue<int> q;
    q.push(idx);
    
    vis[idx] = true;
    
    while(!q.empty())
    {
        int curIdx = q.front();
        q.pop();
        
        cnt++;
        for(auto nxt : adj[curIdx])
        {
            if(vis[nxt]) continue;
            
            vis[nxt] = true;
            q.push(nxt);
        }
    }
    
    cur = max(cur, cnt);
}

int solution(int n, vector<vector<int>> wires) {    
    for(int i = 0; i < n - 1; i++)
    {
        int from = wires[i][0];
        int to = wires[i][1];
        
        adj[from].insert(to);
        adj[to].insert(from);
    }
    
    for(int i = 0; i < n - 1; i++)
    {
        fill(vis, vis + 101, false);
        amount.clear();
            
        int from = wires[i][0];
        int to = wires[i][1];
        
        adj[from].erase(to);
        adj[to].erase(from);
                
        for(int j = 1; j <= n; j++)
        {
            if(vis[j]) continue;
            
            cur = 0;
            
            BFS(j);    
            amount.push_back(cur);
        }
        
        ans = min(ans, abs(amount[0] - amount[1]));
        
        adj[from].insert(to);
        adj[to].insert(from);
    }
    
    return ans;
}
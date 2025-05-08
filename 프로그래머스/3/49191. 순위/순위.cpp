#include <bits/stdc++.h>

using namespace std;

vector<int> adjWin[101];
vector<int> adjLose[101];

bool vis[101];
int cnt[101];

void BFS(int x, vector<int> adj[])
{
    queue<int> q;
    q.push(x);
    vis[x] = true;
    
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        
        for(int nxt : adj[cur])
        {
            if(vis[nxt]) continue;
            vis[nxt] = true;
            cnt[nxt]++;
            q.push(nxt);
        }
    }
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    int m = (int)results.size();
    
    for(int i = 0; i < m; i++)
    {
        int from = results[i][0];
        int to = results[i][1];
        
        adjWin[from].push_back(to);
        adjLose[to].push_back(from);
    }
    
    for(int i = 1; i <= n; i++)
    {
        fill(vis, vis + 101, false);
        BFS(i, adjWin);
        
        fill(vis, vis + 101, false);
        BFS(i, adjLose);
    }
    
    for(int i = 1; i <= n; i++)
    {
        if(cnt[i] == n - 1) answer++;
    }
    
    return answer;
}
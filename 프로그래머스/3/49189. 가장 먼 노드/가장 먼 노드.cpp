#include <bits/stdc++.h>

using namespace std;

vector<int> adj[20001];

int dist[20001];

void BFS(int x)
{
    queue<int> q;
    q.push(x);
    
    dist[x] = 0;
    
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        
        for(auto nxt : adj[cur])
        {
            if(dist[nxt] != INT_MAX) continue;
            dist[nxt] = dist[cur] + 1;
            q.push(nxt);
        }    
    }
    
}
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int m = (int)edge.size();
    
    for(int i = 0; i < m; i++)
    {
        int from = edge[i][0];
        int to = edge[i][1];
        
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    
    fill(dist, dist + 20001, INT_MAX);
    
    dist[1] = 0;
    BFS(1);
    
    int maxVal = *max_element(dist + 1, dist + n);
    
    for(int i = 1; i <= n; i++)
    {
        if(maxVal == dist[i]) answer++; 
    }
    
    return answer;
}
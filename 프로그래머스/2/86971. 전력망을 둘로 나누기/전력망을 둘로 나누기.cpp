#include <bits/stdc++.h>

using namespace std;

int graph[101][101];

bool vis[101];

int sz;
void DFS(int x)
{
    for(int i = 1; i <= sz; i++)
    {
        if(graph[x][i] == 0) continue;
        if(vis[i]) continue;
        
        vis[i] = true;
        DFS(i);
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = INT_MAX;
    sz = n;
    int m = (int)wires.size();
    
    // 연결
    for(int i = 0; i < m; i++)
    {
        int from = wires[i][0];
        int to = wires[i][1];
        
        graph[from][to] = 1;
        graph[to][from] = 1;
    }
    
    for(int i = 0; i < m; i++)
    {
        int from = wires[i][0];
        int to = wires[i][1];
      
        // 연결 끊기
        graph[from][to] = 0;
        graph[to][from] = 0;
        
        fill(vis, vis + 101, false);        
        vis[1] = true;
        
        DFS(1);
        
        // 다시 연결
        graph[from][to] = 1;
        graph[to][from] = 1;
        
        int cnt = 0;
        for(int i = 1; i <= n; i++)
        {
            if(vis[i]) cnt++;
        }
        
        cout << "n: " << n << " cnt: " << cnt << "\n";
        answer = min(answer, abs((n - cnt) - cnt));
    }
    
    return answer;
}
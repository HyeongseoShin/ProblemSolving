// 각 실행마다 실제 연결을 끊는 것이 아니라
// 각 전선 별로 <출발점, 도착점> 모두 방문 표시를 해서
// 출발점 --> 도착점으로 가는 전선을 건너 뛰는 것처럼 실행하면 됨

#include <bits/stdc++.h>

using namespace std;

vector<int> adj[101];

bool vis[101];

int sz;

int cnt;
void BFS(int x, int y)
{
    queue<int> q;
    q.push(x);
    
    vis[x] = true;
    vis[y] = true;
    
    cnt++;
    
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        
        for(auto nxt : adj[cur])
        {
            if(vis[nxt]) continue;
            vis[nxt] = true;
            cnt++;
            q.push(nxt);
        }
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
        
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    
    // 연결 끊기
    for(int i = 0; i < m; i++)
    {
        int from = wires[i][0];
        int to = wires[i][1];
        
        cnt = 0;
        fill(vis, vis + 1 + n, false);
        BFS(from, to);
        
        answer = min(answer, abs((n - cnt) - cnt));
    }
    
    return answer;
}
#include <bits/stdc++.h>

using namespace std;

int ans = 0;
int N, K, st;

vector<pair<int, int>> adj[101];

vector<int> orders;

void bfs()
{
    bool isInfected[101];
    memset(isInfected, false, sizeof(isInfected));
    
    bool vis[101];
    
    // 시작점 감염
    isInfected[st] = true;
    
    for(int i = 0; i < (int)orders.size(); i++)
    {
        memset(vis, false, sizeof(vis));
        
        queue<int> q;
        
        for(int j = 1; j <= N; j++)
        {
            if(isInfected[j])
            {
                vis[j] = true;
                q.push(j);
            }
        }
        
        // 현재 열린 파이프
        int curOpened = orders[i];
        
        while(!q.empty())
        {
            int cur = q.front();
            q.pop();
            
            // cout << "cur: " << cur << "\n";
            
            for(auto [nxtPipe, nxt] : adj[cur])
            {
                if(vis[nxt]) continue;
                if(nxtPipe != curOpened) continue;
                
                isInfected[nxt] = true;
                vis[nxt] = true;
                q.push(nxt);
            }
        }
    }
    
    int cnt = 0;
    for(int i = 1; i <= N; i++)
    {
        if(isInfected[i]) cnt++;
    }
    
    ans = max(ans, cnt);
}

// 조합 찾기
void getAns(int cnt)
{
    if(cnt >= K)
    {
        bfs();
        return;
    }
        
    for(int i = 1; i <= 3; i++)
    {
        int sz = (int)orders.size();
        
        // 직전과 같은 파이프는 열지 않음
        if(sz > 0 && orders[sz-1] == i) continue;
        
        orders.push_back(i);
        getAns(cnt+1);
        orders.pop_back();
    }
}
int solution(int n, int infection, vector<vector<int>> edges, int k) {
    N = n;
    K = k;
    
    st = infection;
    
    // edges 저장
    for(int i = 0; i < n-1; i++)
    {
        int x = edges[i][0];
        int y = edges[i][1];
        int type = edges[i][2];
        
        adj[x].push_back({type, y});
        adj[y].push_back({type, x});
    }
    
    getAns(0);
    
    return ans;
}
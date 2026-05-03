#include <bits/stdc++.h>

using namespace std;

int ans = 0;
int n;

vector<int> adj[20];

// <i, 양의 수, 늑대의 수>
bool vis[20][20][20];

// 백트래킹
void dfs(int cur, int curSheep, int curWolf, vector<int> &info)
{
    if(curSheep <= curWolf) return; // 늑대가 더 많은 경우 불가능
    ans = max(ans, curSheep);
    
    for(int nxt : adj[cur])
    {
        // 양인 경우
        if(info[nxt] == 0 && !vis[nxt][curSheep+1][curWolf])
        {
            info[nxt] = -1;
            vis[nxt][curSheep+1][curWolf] = true;
            
            dfs(nxt, curSheep+1, curWolf, info);
            
            vis[nxt][curSheep+1][curWolf] = false;
            info[nxt] = 0;
        }
        
        // 늑대인 경우
        else if(info[nxt] == 1)
        {
            if(curSheep > curWolf+1 && !vis[nxt][curSheep][curWolf+1])
            {
                info[nxt] = -1;
                vis[nxt][curSheep][curWolf+1] = true;

                dfs(nxt, curSheep, curWolf+1, info);

                vis[nxt][curSheep][curWolf+1] = false;
                info[nxt] = 1;
            }
        }
        
        // 이미 지난 곳인 경우
        else 
        {
            if(!vis[nxt][curSheep][curWolf])
            {
                vis[nxt][curSheep][curWolf] = true;
                dfs(nxt, curSheep, curWolf, info);
                vis[nxt][curSheep][curWolf] = false;    
            }
            
        }
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    n = (int)info.size();
    
    for(int i = 0; i < n - 1; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    info[0] = -1;
    vis[0][1][0] = true;
    dfs(0, 1, 0, info);
    
    return ans;
}
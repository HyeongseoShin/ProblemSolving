#include <bits/stdc++.h>

using namespace std;

bool vis[201];

void DFS(int v, int& n, vector<vector<int>>& computers)
{
    for(int i = 0; i < n; i++)
    {
        if(computers[v][i] == 0) continue;
        if(vis[i]) continue;
        
        vis[i] = true;
        DFS(i, n, computers);
    }
}

int solution(int n, vector<vector<int>> computers)
{   
    int ans = 0;
    
    for(int i = 0; i < n; i++)
    {
        if(vis[i]) continue;    
        vis[i] = true;
        
        DFS(i, n, computers);
        
        ans++;
    }
    
    return ans;
}
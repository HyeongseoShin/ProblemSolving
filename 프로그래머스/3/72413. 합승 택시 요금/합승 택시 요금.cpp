#include <bits/stdc++.h>

using namespace std;

int dist[205][205];
int answer = 0;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    
    for(int i = 1; i < 205; i++)
    {
        for(int j = 1; j < 205; j++)
        {
            if(i == j) continue;
            else dist[i][j] = 1e9;        
        }
    }
    
    for(int i = 0; i < (int)fares.size(); i++)
    {
        int u = fares[i][0];
        int v = fares[i][1];
        int w = fares[i][2];
        
        dist[u][v] = w;
        dist[v][u] = w;
    }
    
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    
    answer = dist[s][a] + dist[s][b];
    
    for(int i = 1; i <= n; i++)
    {
        if(i == s || dist[s][i] == 1e9) continue;
        
        answer = min(answer, dist[s][i] + dist[i][a] + dist[i][b]);
    }
    
    return answer;
}
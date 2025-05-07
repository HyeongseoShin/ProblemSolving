#include <bits/stdc++.h>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int dist[101][101];

int n, m;

void BFS(int x, int y, vector<vector<int>>& maps)
{
    queue<pair<int,int>> q;
    q.push({x, y});
    dist[x][y] = 1;
    
    while(!q.empty())
    {
        auto [curX, curY] = q.front();
        q.pop();
        
        for(int i = 0; i < 4; i++)
        {
            int nX = curX + dx[i];
            int nY = curY + dy[i];
            
            if(nX < 0 || nX >= n || nY < 0 || nY >= m) continue;
            if(maps[nX][nY] == 0) continue;
            if(dist[nX][nY] > dist[curX][curY] + 1)
            {
                dist[nX][nY] = dist[curX][curY] + 1;
                q.push({nX, nY});
            }
        }
    }
}
int solution(vector<vector<int>> maps)
{
    n = (int)maps.size();
    m = (int)maps[0].size();
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            dist[i][j] = INT_MAX;
        }
    }
    
    BFS(0, 0, maps);
    
    if(dist[n-1][m-1] == INT_MAX) return -1;
    return dist[n-1][m-1];
}
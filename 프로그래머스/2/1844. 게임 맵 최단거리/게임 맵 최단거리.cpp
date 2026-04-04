#include <bits/stdc++.h>

using namespace std;

// 0은 벽, 1은 자리
int n, m;
int dist[101][101];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs(vector<vector<int>> maps)
{
    memset(dist, -1, sizeof(dist));
    queue<pair<int, int>> q;
    dist[0][0] = 1;
    q.push({0, 0});
    
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
            if(dist[nX][nY] != -1) continue;
            
            dist[nX][nY] = dist[curX][curY] + 1;
            q.push({nX, nY});
        }
    }
    
    return dist[n-1][m-1];
    
    
}

int solution(vector<vector<int>> maps)
{
    n = maps.size();
    m = maps[0].size();
    
    int answer = bfs(maps);
    return answer;
}
#include <bits/stdc++.h>

using namespace std;

char board[101][101];
int dist[101][101];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void BFS(int cX, int cY, int iX, int iY)
{
    queue<pair<int, int>> q;
    
    q.push({cX, cY});
    
    dist[cX][cY] = 0;
    
    while(!q.empty())
    {
        auto [curX, curY] = q.front();
        q.pop();
        
        for(int i = 0; i < 4; i++)
        {
            int nX = curX + dx[i];
            int nY = curY + dy[i];
            
            if(nX < 0 || nX > 100 || nY < 0 || nY > 100) continue;
            if(board[nX][nY] == 0) continue;
            if(dist[nX][nY] > dist[curX][curY] + 1)
            {
                dist[nX][nY] = dist[curX][curY] + 1;
                q.push({nX, nY});
            }
        }
    }
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY)
{
    // 내부 다 채우기
    for(int i = 0; i < (int)rectangle.size(); i++)
    {
        for(int j = 0; j < (int)rectangle[i].size(); j++)
        {
            rectangle[i][j] *= 2;
        }
        
        int lX = rectangle[i][0];
        int lY = rectangle[i][1];
        
        int rX = rectangle[i][2];
        int rY = rectangle[i][3];
        
        for(int x = lX; x <= rX; x++)
        {
            for(int y = lY; y <= rY; y++)
            {
                board[x][y] = 1;
            }
        }
    }
    
    // 테두리만 남기기
    for(int i = 0; i < (int)rectangle.size(); i++)
    {
        int lX = rectangle[i][0];
        int lY = rectangle[i][1];
        
        int rX = rectangle[i][2];
        int rY = rectangle[i][3];
        
        for(int x = lX + 1; x < rX; x++)
        {
            for(int y = lY + 1; y < rY; y++)
            {
                board[x][y] = 0;
            }
        }
    }
    
    for(int i = 0; i < 101; i++)
    {
        for(int j = 0; j < 101; j++)
        {
            dist[i][j] = INT_MAX;
            // cout << board[i][j] <<" ";
        }
        // cout << "\n";
    }
    
    BFS(characterX * 2, characterY * 2, itemX * 2, itemY * 2);
    
    return dist[itemX * 2][itemY * 2] / 2;
}
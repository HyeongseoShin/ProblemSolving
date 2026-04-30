#include <bits/stdc++.h>

using namespace std;

int n, m;
int ans = 0;

int board[501][501];

// 열마다 뽑을 수 있는 석유 크기
int oilSz[501];

bool vis[501][501];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(int x, int y)
{
    vis[x][y] = true;
    queue<pair<int, int>> q;
    
    q.push({x, y});
    
    unordered_set<int> cols; // 현재 석유가 뽑힐 수 있는 열 번호 목록
    cols.insert(y);
    
    int cnt = 1; // 현재 석유의 크기
    
    while(!q.empty())
    {
        auto [curX, curY] = q.front();
        q.pop();
        
        for(int i = 0; i < 4; i++)
        {
            int nX = curX + dx[i];
            int nY = curY + dy[i];
            
            if(nX < 0 || nX >= n || nY < 0 || nY >= m) continue;
            if(vis[nX][nY]) continue;
            if(board[curX][curY] != board[nX][nY]) continue;
            
            cols.insert(nY);
            cnt++;
            vis[nX][nY] = true;
            q.push({nX, nY});
        }
    }
    
    // cout << "cnt: " << cnt << " - ";
    for(auto col : cols)
    {
        // cout << col << " ";
        oilSz[col] += cnt;
    }
    // cout << "\n";
}

int solution(vector<vector<int>> land) {
    n = (int)land.size();
    m = (int)land[0].size();
    
    // cout << "n: " << n << " m: " << m << "\n";
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            board[i][j] = land[i][j];
        }
    }
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(board[i][j] == 0) continue;
            if(vis[i][j]) continue;
            bfs(i, j);
        }
    }
    
    for(int i = 0; i < m; i++)
    {
        // cout << oilSz[i] << "\n";
        ans = max(ans, oilSz[i]);
    }
    
    return ans;
}
#include <bits/stdc++.h>

using namespace std;

int n, m;
int ans = 0;

int board[501][501]; // 진행 판

int oilSz[501]; // 열마다 뽑을 수 있는 석유 크기

bool vis[501][501]; // 방문 확인 배열

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(int x, int y)
{
    vis[x][y] = true;
    
    queue<pair<int, int>> q;
    q.push({x, y});
    
    set<int> cols; // 현재 석유가 뽑힐 수 있는 열 번호 목록
    cols.insert(y); // 시작 위치 열 저장
    
    int cnt = 1; // 현재 석유의 크기
    
    while(!q.empty())
    {
        auto [curX, curY] = q.front();
        q.pop();
        
        for(int i = 0; i < 4; i++)
        {
            int nX = curX + dx[i];
            int nY = curY + dy[i];
            
            if(nX < 0 || nX >= n || nY < 0 || nY >= m) continue; // 범위 넘으면 패스
            if(vis[nX][nY]) continue; // 방문했으면 패스
            if(board[nX][nY] == 0) continue; // 벽이면 패스
            
            cnt++; // 석유 크기 증가
            cols.insert(nY); // 석유 뽑힐 수 있는 열 추가
            
            vis[nX][nY] = true;
            q.push({nX, nY});
        }
    }
    
    // 뽑힐 수 있는 열들에 현재 석유 크기 업데이트
    for(auto col : cols) oilSz[col] += cnt;
}

int solution(vector<vector<int>> land) {
    n = (int)land.size();
    m = (int)land[0].size();
    
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
            if(board[i][j] == 0) continue; // 벽이면 패스
            if(vis[i][j]) continue; // 이미 방문했으면 패스
            bfs(i, j);
        }
    }
    
    // 석유 가장 많이 뽑을 수 있는 열 선택
    for(int i = 0; i < m; i++) ans = max(ans, oilSz[i]);
    
    return ans;
}
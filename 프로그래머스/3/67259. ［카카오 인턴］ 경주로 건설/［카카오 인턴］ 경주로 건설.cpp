#include <bits/stdc++.h>

using namespace std;

#define MAX 1000001

int n;

// 출발점, 상, 좌, 하, 우
// 코너 여부 : +1 or + 3
int dx[5] = {0, 0, -1, 0, 1};
int dy[5] = {0, -1, 0, 1, 0};

int cost[26][26][5];

int getCost(int curDir, int nDir)
{
    // 출발점이면 무조건 직선
    if(curDir == 0) return 100;
    
    else if(curDir == nDir) return 100;
    else if(curDir > nDir && curDir - 2 == nDir) return 100;
    else if(curDir < nDir && curDir + 2 == nDir) return 100;
    
    else return 600;
}


// 0은 빈 칸, 1은 벽
int getAns(vector<vector<int>> board)
{
    // <비용, x, y, 들어온 방향>
    priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<>> pq;
    cost[0][0][0] = 0;
    pq.push({cost[0][0][0], 0, 0, 0});
    
    while(!pq.empty())
    {
        auto [curCost, curX, curY, curDir] = pq.top();
        pq.pop();
        
        if(cost[curX][curY][curDir] != curCost) continue; // 비용 값 달라져 있으면 패스
        
        for(int nDir = 1; nDir <= 4; nDir++)
        {
            int nX = curX + dx[nDir];
            int nY = curY + dy[nDir];
            
            if(nX < 0 || nX >= n || nY < 0 || nY >= n) continue; // 범위 넘으면 패스
            if(board[nX][nY] == 1) continue; // 벽이면 패스
            
            int nCost = getCost(curDir, nDir);
            
            if(cost[nX][nY][nDir] <= curCost + nCost) continue; // 이미 적은 비용으로 도달 가능하면 패스
            
            cost[nX][nY][nDir] = curCost + nCost;
            pq.push({cost[nX][nY][nDir], nX, nY, nDir});
        }
    }
    
    int ans = MAX;
    for(int i = 1; i <= 4; i++)
    {
        ans = min(ans, cost[n-1][n-1][i]);
    }
    
    return ans;   
}
int solution(vector<vector<int>> board)
{
    n = (int) board.size();
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int dir = 0; dir < 5; dir++)
            {
                cost[i][j][dir] = MAX;    
            }
        }
    }
    
    int answer = getAns(board);
    return answer;
}
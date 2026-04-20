#include <bits/stdc++.h>

using namespace std;

int n, x, m;
int ans = 0;

// 각 로봇의 이동 경로
vector<pair<int, int>> path[105];

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    n = (int)points.size();
    x = (int)routes.size();
    m = (int)routes[0].size();
    
    // 로봇마다 순회
    for(int i = 0; i < x; i++)
    {
        // 시작점 세팅
        int st = routes[i][0];
        
        int curX = points[st-1][0];
        int curY = points[st-1][1];
        
        path[i].push_back({curX, curY});
        
        // 다음 포인트로 이동
        for(int j = 1; j < m; j++)
        {
            int target = routes[i][j];
            int tX = points[target-1][0];
            int tY = points[target-1][1];
            
            while(curX < tX)
            {
                curX++;
                path[i].push_back({curX, curY});
            }
            
            while(curX > tX)
            {
                curX--;
                path[i].push_back({curX, curY});
            }
            
            while(curY < tY)
            {
                curY++;
                path[i].push_back({curX, curY});
            }
            
            while(curY > tY)
            {
                curY--;
                path[i].push_back({curX, curY});
            }   
        }
    }
    
    int maxLen = 0;
    for(int i = 0; i < x; i++)
    {
        maxLen = max(maxLen, (int)path[i].size());
    }
    
    int dangerCnt[105][105];
    
    for(int i = 0; i < maxLen; i++)
    {
        memset(dangerCnt, 0, sizeof(dangerCnt));
        set<pair<int, int>> check;
        for(int j = 0; j < x; j++)
        {
            if(i >= path[j].size()) continue;
            auto [curX, curY] = path[j][i];
            dangerCnt[curX][curY]++;
            check.insert({curX, curY});
        }
        
        for(auto [x, y] : check)
        {
            if(dangerCnt[x][y] > 1) ans++;
        }
    }
    
    
    return ans;
}
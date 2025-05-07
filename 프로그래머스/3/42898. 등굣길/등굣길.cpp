#include <bits/stdc++.h>

using namespace std;

#define MAX 1000000007

int dp[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            dp[i][j] = INT_MAX;
        }
    }
    
    // 웅덩이 위치 표시
    for(int i = 0; i < (int)puddles.size(); i++)
    {
        int x = puddles[i][0];
        int y = puddles[i][1];
        
        dp[y][x] = -1;
    }
    
    dp[1][1] = 1;    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            // 시작점
            if(i == 1 && j == 1) continue;
            
            // 물 웅덩이
            if(dp[i][j] == -1) continue;
            
            int prevLeft = dp[i][j-1];
            int prevUp = dp[i-1][j];
            
            if(prevLeft == INT_MAX || prevLeft == -1) prevLeft = 0;
            if(prevUp == INT_MAX || prevUp == -1) prevUp = 0;
            
            dp[i][j] = (prevLeft + prevUp) % MAX;
        }
    }
    
    answer = dp[n][m];
    
    return answer;
}
#include <bits/stdc++.h>

using namespace std;

#define MAX 121

// dp[i][j]: i까지 봤고 B가 남긴 흔적이 j일때 A가 남긴 흔적의 최솟값
int dp[41][121];

int solution(vector<vector<int>> info, int n, int m) {
    int sz = (int)info.size();
    
    // dp 초기화
    for(int i = 1; i <= sz; i++)
    {
        for(int j = 0; j < m; j++)
        {
            dp[i][j] = MAX;
        }
    }
    
    dp[0][0] = 0;
    
    for(int i = 1; i <= sz; i++)
    {
        int a = info[i-1][0];
        int b = info[i-1][1];
        
        for(int j = 0; j < m; j++)
        {
            // B가 훔치는 경우
            // A vs B가 훔치는 경우 중 더 작은 방법 선택
            if(b <= j)
            {
                dp[i][j] = min(dp[i-1][j] + a, dp[i-1][j - b]);
            }
            
            // A가 훔치는 경우
            else dp[i][j] = dp[i-1][j] + a;
        }
    }
    
    int ans = MAX;
    
    for(int j = 0; j < m; j++)
    {
        ans = min(ans, dp[sz][j]);
    }
    
    if(ans >= n) ans = -1;
    
    return ans;
}
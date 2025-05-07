#include <bits/stdc++.h>

using namespace std;

// dp[i][j] : i, j까지 왔을 때 최대 합
int dp[500][500];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    int n = (int) triangle.size();
    dp[0][0] = triangle[0][0];
    
    for(int i = 1; i < n; i++)
    {
        dp[i][0] = dp[i-1][0] + triangle[i][0];
        for(int j = 1; j <= i; j++)
        {
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
        }
    }
    
    answer = *max_element(dp[n - 1], dp[n - 1] + n);
    return answer;
}
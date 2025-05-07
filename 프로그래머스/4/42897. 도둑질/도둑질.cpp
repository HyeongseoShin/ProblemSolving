#include <bits/stdc++.h>

using namespace std;

#define MAX 1000001

// dp[n] : n집까지 봤을 때 훔칠 수 있는 돈의 최댓값

// 첫 번째 집 터는 경우
int dp1[MAX];

// 첫 번째 집 안 터는 경우
int dp2[MAX];

int solution(vector<int> money) {
    int n = (int) money.size();
    
    // 첫 번째 집 털기 (마지막 집 절대 안 텀)
    dp1[0] = money[0]; // 첫 번째 집 털고
    dp1[1] = dp1[0]; // 두 번째 집은 안터니까 첫 번째 집 턴 돈
    
    for(int i = 2; i < n - 1; i++)
    {
        dp1[i] = max(dp1[i-1], dp1[i-2] + money[i]);
    }
    
    // 첫 번째 집 안 털기 (마지막 집 털 수도)
    dp2[0] = 0;
    dp2[1] = money[1];
    
    for(int i = 2; i < n; i++)
    {
        dp2[i] = max(dp2[i-1], dp2[i-2] + money[i]);
    }
    
    return max(dp1[n-2], dp2[n-1]);
}
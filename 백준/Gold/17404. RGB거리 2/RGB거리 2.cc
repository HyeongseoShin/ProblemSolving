#include <bits/stdc++.h>

using namespace std;

#define MAX 987654321

int n;

int colors[1001][3];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    

    for(int i = 0; i < n; i++)
    {
        cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
    }

    int ans = MAX;

    // 1번집 != N번집 조건 때문에 1번집이 R, G, B인 경우 3가지 나눠서 계산
    for(int start = 0; start < 3; start++)
    {
        // dp[i][j]: i번째 집을 j로 색칠했을 때 비용의 최솟값
        int dp[1001][3];

        for(int i = 0; i < 3; i++)
        {
            if(i == start) dp[0][i] = colors[0][i];
            else dp[0][i] = MAX;
        }

        for(int i = 1; i < n; i++)
        {
            dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + colors[i][0];
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + colors[i][1];
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + colors[i][2];
        }

        for(int i = 0; i < 3; i++)
        {
            if(i == start) continue;
            ans = min(ans, dp[n-1][i]);
        }
    }

    cout << ans << "\n";

    return 0;
}
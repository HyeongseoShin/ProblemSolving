#include <bits/stdc++.h>

using namespace std;

int t, k;

// dp[i][j] : i ~ j번째 파일 합치는 데 필요한 최소 비용
int dp[501][501];

// sum[i] : 1 ~ i번째 파일 크기의 합
int sum[501];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> k;

        for(int i = 1; i <= k; i++)
        {
            int x;
            cin >> x;

            sum[i] = sum[i-1] + x;
        }

        // 합칠 범위의 크기
        // i == 2 -> 1~2, 3~4, ...
        // i == 5 -> 1~5, 2~6, ...
        for(int i = 1; i <= k; i++)
        {
            // 합칠 파일의 시작 위치
            for(int j = 1; j <= k - i; j++)
            {
                dp[j][i+j] = INT_MAX;

                // 중간에 나눌 위치
                // i = 5, j = 1, m = 2 -> 1~2, 3~5
                // i == 8, j = 3, m = 6 -> 3~6, 7~10
                for(int m = j; m < i + j; m++)
                {
                    dp[j][i+j] = min(dp[j][i+j], dp[j][m] + dp[m+1][i+j] + sum[i+j] - sum[j-1]);
                }
            }
        }

        cout << dp[1][k] << "\n";
    }

    return 0;
}
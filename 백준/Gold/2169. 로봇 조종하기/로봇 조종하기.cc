#include <bits/stdc++.h>

using namespace std;

int n, m;

// dp[i][j] : [i][j]까지 탐사했을 때 최대 가치의 합
int dp[1005][1005];
int l[1005][1005];
int r[1005][1005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> dp[i][j];
            r[i][j] = l[i][j] = dp[i][j];
        }
    }

    // 0행은 오른쪽으로만 진행할 수 있음
    for(int j = 1; j < m; j++)
    {
        dp[0][j] = dp[0][j] + dp[0][j-1];
    }

    // 1행 부터는 (위쪽 vs 왼쪽) vs (위쪽 vs 오른쪽) 값 중 최댓값을 고르자
    for(int i = 1; i < n; i++)
    {
        // 위쪽 vs 왼쪽
        l[i][0] = l[i][0] + dp[i-1][0];
        for(int j = 1; j < m; j++)
        {
            l[i][j] = max(l[i][j-1], dp[i-1][j]) + l[i][j];
        }

        // 위쪽 vs 오른쪽
        r[i][m-1] = r[i][m-1] + dp[i-1][m-1];
        for(int j = m-2; j >= 0; j--)
        {
            r[i][j] = max(r[i][j+1], dp[i-1][j]) + r[i][j];
        }

        // 최종
        for(int j = 0; j < m; j++)
        {
            dp[i][j] = max(l[i][j], r[i][j]);
        }
    }

    // for(int i = 0; i < n; i++)
    // {
    //     for(int j = 0; j < m; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    cout << dp[n-1][m-1] << "\n";


    return 0;
}
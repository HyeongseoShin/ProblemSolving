#include <bits/stdc++.h>

using namespace std;

int n;
int board[501][501];

int ans = 0;

// dp[i][j] : (i, j)까지 오는 데 최대 합
int dp[501][501];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            cin >> board[i][j];
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + board[i][j];
        }
    }

    int ans = *max_element(dp[n] + 1, dp[n] + n + 1);
    cout << ans << "\n";

    return 0;
}
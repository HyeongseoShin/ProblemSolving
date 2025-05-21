#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int testCase;
    cin >> testCase;

    for(int t = 1; t <= testCase; t++)
    {
        int n;
        cin >> n;

        int board[2][100001];
        
        for(int i = 0; i < 2; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int x;
                cin >> x;
                board[i][j] = x;
            }
        }

        // dp[i][j] : (i, j) 까지 오는 데에 고른 스티커 점수의 최대 합
        int dp[2][100001];

        // dp 초기화
        dp[0][0] = board[0][0];
        dp[1][0] = board[1][0];

        dp[0][1] = dp[1][0] + board[0][1];
        dp[1][1] = dp[0][0] + board[1][1];

        for(int i = 2; i < n; i++)
        {
            dp[0][i] = max(dp[1][i-1], dp[1][i-2]) + board[0][i];
            dp[1][i] = max(dp[0][i-1], dp[0][i-2]) + board[1][i];
        }

        cout << max(dp[0][n-1], dp[1][n-1]) << "\n";
    }

    return 0;
}
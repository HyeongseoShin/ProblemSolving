// https://www.acmicpc.net/problem/15989

#include <bits/stdc++.h>

using namespace std;

int dp[10001][4];
int n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    dp[1][1] = 1;
    dp[2][1] = 1;
    dp[2][2] = 1;
    dp[3][1] = 1;
    dp[3][2] = 1;
    dp[3][3] = 1;

    for(int i = 4; i <= 10000; i++)
    {
        dp[i][1] = dp[i-1][1];
        dp[i][2] = dp[i-2][1] + dp[i-2][2];
        dp[i][3] = dp[i-3][1] + dp[i-3][2] + dp[i-3][3];
    }

    while(n--)
    {
        int x;
        cin >> x;

        cout << dp[x][1] + dp[x][2] + dp[x][3] << "\n";
    }

    return 0;
}
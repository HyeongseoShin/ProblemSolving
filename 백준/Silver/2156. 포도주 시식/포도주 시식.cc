#include <bits/stdc++.h>

using namespace std;

int n;

int wine[10001];

int dp[10001][3]; // dp[i][j] : i번째 포도주까지 j번 연속으로 왔을 때 마신 최대 포도주 양

int ans = 0;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        cin >> wine[i];
    }

    dp[1][1] = wine[1];

    dp[2][0] = max({dp[1][0], dp[1][1], dp[1][2]});
    dp[2][1] = wine[2];
    dp[2][2] = dp[1][1] + wine[2];

    for(int i = 3; i <= n; i++)
    {
        dp[i][0] = max({dp[i-1][0], dp[i-1][1], dp[i-1][2]});
        dp[i][1] = dp[i-1][0] + wine[i];
        dp[i][2] = dp[i-1][1] + wine[i];

        // cout << "dp[" << i << "][0]: " << dp[i][0] << "\n";
        // cout << "dp[" << i << "][1]: " << dp[i][1] << "\n";
        // cout << "dp[" << i << "][2]: " << dp[i][2] << "\n";
        // cout << "======================\n";

    }

    ans = max({dp[n][0], dp[n][1], dp[n][2]});

    // cout << dp[n][0] << " " <<  dp[n][1] << " " << dp[n][2] << "\n";

    cout << ans << "\n";

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int n, k;

int coins[101];

// dp[i] : 동전의 합이 i일때 사용한 동전의 최소 개수
int dp[10001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    // fill(dp, dp + n + 1, INT_MAX);

    for(int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    for(int i = 1; i <= k; i++)
    {
        int tmp = INT_MAX;
        for(int j = 0; j < n; j++)
        {
            if(i - coins[j] < 0) continue;
            if(dp[i - coins[j]] == INT_MAX) continue;
            tmp = min(tmp, dp[i-coins[j]] + 1);
        }

        dp[i] = tmp;
        // cout << "i: " << i << " dp[i] : " << dp[i] << "\n";
    }

    if(dp[k] == INT_MAX) dp[k] = -1;

    cout << dp[k] << "\n";

    return 0;
}
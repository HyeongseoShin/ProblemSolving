// https://www.acmicpc.net/problem/2293

// DP, 냅색

#include <bits/stdc++.h>

using namespace std;

int n, k;

int coins[101];

// dp[i] : i원을 만들 수 있는 경우의 수
int dp[10001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for(int i = 1; i <= n; i++)
    {
        cin >> coins[i];
    }

    dp[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = coins[i]; j <= k; j++)
        {
            dp[j] += dp[j - coins[i]];
        }
    }

    cout << dp[k] << "\n";



    return 0;
}
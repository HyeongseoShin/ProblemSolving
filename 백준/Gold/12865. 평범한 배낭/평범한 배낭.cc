#include <bits/stdc++.h>

using namespace std;

int n, k;

// 무게, 가치
int w[101];
int v[101];

// dp[i][j] : i번쨰 물건까지 봤고 무게 j일때 가치 최댓값
int dp[101][100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for(int i = 1; i <= n; i++)
    {
        cin >> w[i] >> v[i];
    }

    // 물건의 개수
    for(int i = 1; i <= n; i++)
    {
        // 현재 가방의 무게
        for(int j = 1; j <= k; j++)
        {
            // 현재 가방에 넣을 수 있으면
            // 고르거나 안 고르거나
            if(w[i] <= j)
            {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j - w[i]] + v[i]);
            }
            else dp[i][j] = dp[i-1][j];
        }
    }

    cout << dp[n][k] << "\n";

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

// 테이블 정의
// dp[i][j]: i번쨰 아이템까지 봤고 가방 최대 무게가 j일때 최대 가치
long long dp[101][100001];

// (무게, 가치)
vector<pair<int, int>> v;

int n, k;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    v.resize(n + 1);

    for(int i = 1; i <= n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    for(int i = 1; i <= n; i++)
    {
        int weight = v[i].first;
        int value = v[i].second;

        for(int j = 1; j <= k; j++)
        {
            if(weight > j)
            {
                dp[i][j] = dp[i - 1][j];
            }

            else
            {
                // 현재 아이템을 선택하거나 or 선택하지 않거나
                dp[i][j] = max(dp[i - 1][j - weight] + value, dp[i - 1][j]);
            }
        }
    }

    cout << dp[n][k] << "\n";

    return 0;
}
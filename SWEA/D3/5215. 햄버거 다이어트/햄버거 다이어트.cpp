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
        int n, l;
        cin >> n >> l;

        int score[21];
        int calories[21];

        for(int i = 1; i <= n; i++)
        {
            cin >> score[i] >> calories[i];
        }

        // dp[i][j] : 최대 칼로리가 j이고 i번째 재료까지 봤을 때 점수의 최대값
        int dp[21][10001];
        memset(dp, 0, sizeof(dp));

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= l; j++)
            {
                if(calories[i] <= j)
                {
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j - calories[i]] + score[i]);
                }
                else dp[i][j] = dp[i-1][j];
            }
        }

        cout << "#" << t << " " << dp[n][l] << "\n";


    }
    return 0;
}
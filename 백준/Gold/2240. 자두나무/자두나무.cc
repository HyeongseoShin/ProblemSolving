#include <bits/stdc++.h>

using namespace std;

int t, w;

int order[1001];

// dp[i][j] : i초까지 j번 움직였을 때 받을 수 있는 자두의 최대 개수
int dp[1001][31];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t >> w;

    for(int i = 1; i <= t; i++)
    {
        cin >> order[i];
    }

    if(order[1] == 1) dp[1][0] = 1;
    else dp[1][1] = 1;

    // 전체 시간 순회
    for(int i = 2; i <= t; i++)
    {
        dp[i][0] = dp[i-1][0];

        if(order[i] == 1) dp[i][0]++;

        // 움직이는 횟수 확인
        for(int j = 1; j <= w && j <= i; j++)
        {
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]);

            if(j % 2 == 0 && order[i] == 1) dp[i][j]++;
            if(j % 2 == 1 && order[i] == 2) dp[i][j]++;
        }
    }


    int ans = -1;
    for(int i = 0; i <= w; i++)
    {
        ans = max(ans, dp[t][i]);
    }

    cout << ans << "\n";


    return 0;
}
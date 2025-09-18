#include <bits/stdc++.h>

using namespace std;

int t, w;

int pos[1001];

// dp[i][j] : i초에 j번 움직였을 때 받을 수 있는 최대 자두의 개수
int dp[1001][31];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t >> w;

    for(int i = 1; i <= t; i++)
    {
        cin >> pos[i];
    }

    if(pos[1] == 1) dp[1][0] = 1;
    else dp[1][1] = 1;

    for(int i = 2; i <= t; i++)
    {
        int cur = pos[i];

        for(int j = 0; j <= w; j++)
        {
            dp[i][j] = dp[i-1][j];

            if(j > 0) dp[i][j] = max(dp[i][j], dp[i-1][j-1]);

            // 1번 나무에서 떨어지면 j가 짝수이면 += 1
            if(cur == 1 && j % 2 == 0) dp[i][j]++;
            
            // 2번 나무에서 떨어지면 j가 홀수이면 += 1
            else if(cur == 2 && j % 2 == 1) dp[i][j]++;
        }
    }

    int ans = 0;
    for(int i = 0; i <= w; i++)
    {
        ans = max(ans, dp[t][i]);
    }

    cout << ans << "\n";

    return 0;
}
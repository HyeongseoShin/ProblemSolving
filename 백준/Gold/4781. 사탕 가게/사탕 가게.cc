#include <bits/stdc++.h>

using namespace std;

int n; // 사탕 종류
double m; // 돈 양

int money;

pair<int, int> candy[5001]; // <칼로리, 가격>

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(true)
    {
        cin >> n >> m;

        if(n == 0) break;

        money = (int)(m * 100 + 0.5);

        for(int i = 1; i <= n; i++)
        {
            int c;
            double p;

            cin >> c >> p;

            candy[i] = {c, (int)(p * 100 + 0.5)};
        }

        // dp[i] : i만큼 돈 썼을 떄 최대 칼로리
        int dp[10001]; 
        memset(dp, 0, sizeof(dp));

        // 사탕 전체 순회
        for(int i = 1; i <= n; i++)
        {
            auto [curC, curP] = candy[i];

            // 현재 쓸 수 있는 돈이 j일 때
            for(int j = curP; j <= money; j++)
            {
                dp[j] = max(dp[j], dp[j - curP] + curC);
            }
        }

        int ans = 0;

        for(int i = 1; i <= money; i++) ans = max(ans, dp[i]);
        
        cout << ans << "\n";
    }

    return 0;
}
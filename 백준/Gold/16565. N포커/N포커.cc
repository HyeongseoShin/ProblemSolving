#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MOD 10007

int n;

ll ans = 0;

// dp[i][j] : iCj한 값
ll dp[53][53];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i <= 52; i++)
    {
        dp[i][0] = dp[i][i] = 1;
    }

    for(int i = 1; i <= 52; i++)
    {
        for(int j = 1; j <= 52; j++)
        {
            dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]) % MOD;
        }
    }

    for(int i = 1; i <= n / 4; i++)
    {
        int ways = (dp[13][i] * dp[52 - 4*i][n - 4*i]) % MOD;

        if(i % 2 == 1) ans = (ans + ways) % MOD;
        else ans = (ans - ways + MOD) % MOD;
    }

    cout << ans << "\n";
    

    return 0;
}
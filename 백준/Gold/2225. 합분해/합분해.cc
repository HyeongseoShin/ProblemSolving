#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MOD 1000000000

int n, k;

// dp[i][j] : j개 숫자 썼을 때 i만드는 경우의 수
ll dp[201][201];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for(int i = 0; i <= n; i++) dp[i][1] = 1;
    for(int j = 1; j <= k; j++) dp[0][j] = 1;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 2; j <= k; j++)
        {
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
        }  
    }

    cout << dp[n][k] << "\n";

    return 0;
}
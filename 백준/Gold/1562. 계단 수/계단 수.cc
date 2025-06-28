#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000000

typedef long long ll;

int n;

ll ans = 0;

// dp[i][j][k] : (현재 수의 자리수, 마지막 숫자, 비트)
ll dp[101][10][1 << 10];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    if(n < 10)
    {
        cout << "0\n";
        return 0;
    }

    
    // 초기 상태 설정
    // 한자리수일 때 0으로 시작 불가능
    for(int i = 1; i <= 9; i++)
    {
        dp[1][i][1 << i] = 1;
    }

    // 자릿수
    for(int i = 2; i <= n; i++)
    {
        // 마지막 숫자
        for(int j = 0; j <= 9; j++)
        {
            // 비트
            for(int k = 0; k < (1 << 10); k++)
            {
                // 마지막 숫자가 0이면 1만 가능
                if(j == 0)
                {
                    dp[i][j][k | (1 << j)] += dp[i-1][j+1][k] % MOD;
                }

                // 마지막 숫자가 9이면 8만 가능
                else if(j == 9)
                {
                    dp[i][j][k | (1 << j)] += dp[i-1][j-1][k] % MOD;
                }
                
                // 아니면 -1 or +1 가능
                else
                {
                    dp[i][j][k | (1 << j)] += (dp[i-1][j+1][k] + dp[i-1][j-1][k]) % MOD;
                }
            }
        }
    }

    ll ans = 0;

    // 자리수가 n이고 i로 끝나는 수 중 0 ~ 9가 모두 포함된 수의 개수
    for(int i = 0; i <= 9; i++)
    {
        ans = (ans + dp[n][i][(1 << 10) - 1]) % MOD; 
    }

    cout << ans << "\n";


    return 0;
}
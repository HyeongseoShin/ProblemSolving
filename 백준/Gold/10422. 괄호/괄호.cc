#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
typedef long long ll;

int t;

// dp[i] : 길이가 i인 올바른 괄호 문자열의 개수
ll dp[5010];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    dp[0] = 1;
    for(int i = 2; i <= 5000; i += 2)
    {
        for(int j = 0; j <= i - 2; j += 2)
        {
            dp[i] = (dp[i] + dp[j] * dp[i - 2 - j]) % MOD;
        }
    }

    while(t--)
    {
        int l;
        cin >> l;
        cout << dp[l] << "\n"; 
    }

    return 0;
}
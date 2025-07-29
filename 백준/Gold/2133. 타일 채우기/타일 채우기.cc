#include <bits/stdc++.h>

using namespace std;

int n;

int dp[40];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    if(n % 2 == 1)
    {
        cout << "0\n";
        return 0;
    }

    dp[0] = 1;
    dp[2] = 3;

    for(int i = 4; i <= n; i += 2)
    {
        dp[i] = dp[i-2] * 3;

        for(int j = i - 4; j >= 0; j -= 2)
        {
            dp[i] += (dp[j] * 2);
        }
    }

    cout << dp[n] << "\n";

    return 0;
}
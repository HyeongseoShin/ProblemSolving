#include <bits/stdc++.h>

using namespace std;

int dp[4001][4001];

string s1, s2;
int n, m;

int ans = -1;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s1 >> s2;
    
    n = s1.length();
    m = s2.length();

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(s1[i-1] == s2[j-1])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
            }

            else dp[i][j] = 0;

            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans << "\n";

    return 0;
}
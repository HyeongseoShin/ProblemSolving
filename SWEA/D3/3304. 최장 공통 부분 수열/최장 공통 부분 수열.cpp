#include <bits/stdc++.h>

using namespace std;

// dp[s1 알파벳][s2 알파벳] : 현재까지 부분 s1 & 현재까지 부분 s2의 LCS 길이
int dp[1001][1001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int testCase;
    cin >> testCase;

    for(int t = 1; t <= testCase; t++)
    {
        string s1, s2;
        cin >> s1 >> s2;

        int n1 = (int)s1.length();
        int n2 = (int)s2.length();

        memset(dp, 0, sizeof(dp));
        
        for(int i = 1; i <= n1; i++)
        {
            for(int j = 1; j <= n2; j++)
            {
                if(s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        cout << "#" << t << " " << dp[n1][n2] << "\n";

    }
    return 0;
}
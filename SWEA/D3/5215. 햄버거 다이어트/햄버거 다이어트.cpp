// Knapsack Problem (DP)

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int testCase;
    cin >> testCase;
    
    for(int t = 1; t <= testCase; t++)
    {
        int n, l;

        cin >> n >> l;

        int scores[21];
        int calories[21];
        
        for(int i = 1; i <= n; i++)
        {
            cin >> scores[i] >> calories[i];
        }
        
        int dp[21][10001];
        
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= l; j++)
            {
                if(calories[i] <= j)
                {
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j - calories[i]] + scores[i]);
                }
                
                else dp[i][j] = dp[i-1][j];
            }
        }
        
        cout << "#" << t << " " << dp[n][l] << "\n";
    }
    return 0;
}
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
        int n, k;
        
        cin >> n >> k;
        
        int weights[101];
        
        int values[101];
        
        // dp[i][j] : i까지 봤고 무게가 j일때 최대 가치
        int dp[101][1001];
        
        for(int i = 1 ; i <= n; i++)
        {
            cin >> weights[i] >> values[i];
        }
        
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= k; j++)
            {
                // 가방에 넣을 수 있으면
                if(weights[i] <= j)
                {
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j - weights[i]] + values[i]);

                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }

            }
        }
        
		cout << "#" << t << " " << dp[n][k] << "\n"; 
       
    }
    return 0;
}
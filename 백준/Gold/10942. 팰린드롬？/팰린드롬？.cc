#include <bits/stdc++.h>

using namespace std;

int n, m;

int nums[2001];

// dp[i][j] : i ~ j까지 팰린드롬이면 true
bool dp[2001][2001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        cin >> nums[i];
    }
    
    // 길이 1
    for(int i = 1; i <= n; i++)
    {
        dp[i][i] = true;
    }
    
    // 길이 2
    for(int i = 1; i < n; i++)
    {
        if(nums[i] == nums[i+1]) dp[i][i+1] = true;
    }

    // 길이 3이상
    for(int len = 3; len <= n; len++)
    {
        for(int i = 1; i <= n - len + 1; i++)
        {
            int j = i + len - 1;

            // 양 끝이 같고 안쪽도 팰린드롬이면
            if(nums[i] == nums[j] && dp[i+1][j-1])
            {
                dp[i][j] = true;
            }
        }
    }

    cin >> m;

    while(m--)
    {
        int s, e;
        cin >> s >> e;
        
        if(dp[s][e]) cout << "1\n";
        else cout << "0\n";
    }


    return 0;
}
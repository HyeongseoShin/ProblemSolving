#include <bits/stdc++.h>

using namespace std;

// dp[i] : i번째 원소까지 가장 긴 증가하는 부분 수열의 길이
int dp[1001];

// rDp[i] : i번째 원소까지 가장 긴 감소하는 부분 수열의 길이
int rDp[1001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int nums[1001];

    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
        dp[i] = 1;
        rDp[i] = 1;
    }

    // 증가하는 부분 수열 DP 업데이트
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(nums[j] < nums[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // 감소하는 부분 수열 DP 업데이트
    for(int i = n - 1; i >= 0; i--)
    {
        for(int j = n - 1; j > i; j--)
        {
            if(nums[j] < nums[i])
            {
                rDp[i] = max(rDp[i], rDp[j] + 1);
            }
        }
    }
    
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        ans = max(ans, dp[i] + rDp[i]);
    }

    cout << ans - 1 << "\n";


    return 0;
}
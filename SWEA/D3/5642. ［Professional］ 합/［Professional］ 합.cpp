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
        int n;
        cin >> n;

        int nums[100005];
        for(int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }

        int dp[100005];
        fill(dp, dp + n, 0);

        dp[0] = nums[0];

        int ans = dp[0];

        for(int i = 1; i < n; i++)
        {
            dp[i] = max(dp[i-1] + nums[i], nums[i]);
            ans = max(ans, dp[i]);
        }

        cout << "#" << t << " " << ans << "\n";
    }

    return 0;
}
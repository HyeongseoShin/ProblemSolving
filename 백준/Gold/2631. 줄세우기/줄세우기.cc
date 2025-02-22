#include <bits/stdc++.h>

using namespace std;

int n;
int v[202];
int dp[202]; // dp[i] = i번째에서 끝나는 최장 증가 수열의 길이

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    int longest = 0;
    for(int i = 1; i <= n; i++)
    {
        dp[i] = 1;
        for(int j = 1; j < i; j++)
        {
            if(v[i] > v[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        longest = max(longest, dp[i]);
    }

    cout << n - longest << "\n";

    return 0;
}
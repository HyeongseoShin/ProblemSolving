#include <bits/stdc++.h>

using namespace std;

int n;

int dp[202];

vector<int> v;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        v.push_back(x);
    }

    int longest = 0;

    for(int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for(int j = 0; j < i; j++)
        {
            if(v[i] > v[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        longest = max(longest, dp[i]);
    }

    cout<< n - longest << "\n";

    return 0;
}
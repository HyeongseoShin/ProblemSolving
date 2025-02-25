#include <bits/stdc++.h>

using namespace std;

int n, test = 3;

vector<pair<int, int>> coins;

int dp[50001]; // dp[i] : 금액 i를 만들 수 있으면 1, 아니면 0

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(test--)
    {
        cin >> n;
        int sum = 0;

        coins.clear();
        for(int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;

            coins.push_back({a, b});

            sum += (a * b);
        }

        // 총합이 홀수면 불가능
        if(sum % 2 == 1)
        {
            cout << "0\n";
            continue;
        }

        fill(dp, dp + 50001, 0);
        dp[0] = 1;

        for(auto [type, cnt] : coins)
        {
            for(int i = sum / 2; i >= type; i--)
            {
                if(dp[i - type] != 0)
                {
                    for(int j = 0; (j < cnt) && (i + j * type <= sum / 2); j++)
                    {
                        dp[i + j * type] = 1;
                    }
                }
            }
        }

        
        cout << dp[sum / 2] << "\n";
    }

    return 0;
}
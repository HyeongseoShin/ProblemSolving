#include <bits/stdc++.h>

using namespace std;

int n;

// dp[i] : i를 만들 수 있으면 1, 없으면 0
int dp[50001];
vector<pair<int, int>> coins;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 3;

    while(t--)
    {
        int sum = 0;
        coins.clear();
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;

            coins.push_back({a, b});
            sum += (a * b);
        }

        // 총합이 홀수면 불가능
        if(sum % 2 != 0)
        {
            cout << "0\n";
            continue;
        }

        fill(dp, dp + 50001, 0);
        // 0원 만들 수 있음
        dp[0] = 1;

        for(auto [coin, cnt] : coins)
        {
            // sum / 2부터 현재 동전까지 검사하며
            for(int i = sum / 2; i >= coin; i--)
            {
                // 현재 동전 + 다른 동전으로 i값을 만들 수 있다면
                if(dp[i - coin] == 1)
                {
                    // 현재 동전의 개수만큼 확인하며
                    // 현재 목표 값 + 현재 동전 종류 * 개수 <= 최종 목표이면
                    for(int j = 0; (j < cnt) && (i + j * coin <= sum / 2); j++)
                    {
                        dp[i + j * coin] = 1;
                    }
                }
            }
        }

        cout << dp[sum / 2] << "\n";
    }

    return 0;
}
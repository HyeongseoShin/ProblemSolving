#include <bits/stdc++.h>

using namespace std;

int n;

// stick[i] : 성냥을 i개 썼을 때 만들 수 있는 가장 작은 수
int stick[8] = {0, 0, 1, 7, 4, 2, 0, 8};

// dp[i] : 성냥개비 i를 사용해 만들 수 있는 최소값
long long dp[105];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    fill(dp, dp + 105, LLONG_MAX);

    dp[2] = 1;
    dp[3] = 7;
    dp[4] = 4;
    dp[5] = 2;
    dp[6] = 6;
    dp[7] = 8;
    dp[8] = 10;

    for(int i = 9; i <= 100; i++)
    {
        for(int j = 2; j <= 7; j++)
        {
            dp[i] = min(dp[i], dp[i-j] * 10 + stick[j]);
        }
        
    }

    while(n--)
    {
        int t;
        cin >> t;

        // 가장 작은 수 - 최대한 많이 쓰면서 작은 수
        cout << dp[t] << " ";

        // 가장 큰 수 (1 & 7로만 이루어짐)
        string maxNum = "";
        if(t % 2 == 0)
        {
            for(int i = 0; i < t / 2; i++)
            {
                maxNum += "1";
            }
        }

        else
        {
            maxNum += "7";
            for(int i = 0; i < t / 2 - 1; i++)
            {
                maxNum += "1";
            }
        }

        cout << maxNum << "\n";

        
    }

    return 0;
}
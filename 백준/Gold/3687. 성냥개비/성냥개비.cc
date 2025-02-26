#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll dp[101];

// minNum[i] = 성냥 i개를 사용해 만들 수 있는 가장 작은 한 자리 수
int minNum[8] = {0, 0, 1, 7, 4, 2, 0, 8};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    while(n--)
    {
        int input;
        cin >> input;

        // 최소 수 구하기
        // dp[n] = n개의 성냥으로 구성 가능한 최솟값
        fill(dp, dp + 101, LLONG_MAX);

        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 7;
        dp[4] = 4;
        dp[5] = 2;
        dp[6] = 6;
        dp[7] = 8;

        for(int i = 8; i <= input; i++)
        {
            for(int j = 2; j <= 7; j++)
            {
                dp[i] = min(dp[i], dp[i-j] * 10 + minNum[j]);
            }
            
        }

        // 최대 수 구하기
        // 홀수 = (input / 2 - 1)만큼 1, 맨 앞에 7
        // 짝수 = (input / 2)만큼 1
        string maxVal = "";
        if(input % 2 == 1)
        {
            maxVal += '7';
            for(int i = 0; i < (input / 2 -1); i++) maxVal += '1';
        }
        else
        {
            for(int i= 0; i < (input / 2); i++) maxVal += '1';
        }

        cout << dp[input] << " " << maxVal << "\n";
    }

    return 0;
}
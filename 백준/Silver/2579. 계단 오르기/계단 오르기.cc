#include <bits/stdc++.h>

using namespace std;

int n;

// 계단 별 점수
int stairs[301];

// dp[i][j]: i 계단까지 오는 데 직전에 j 스텝 밟았을 때 최대 점수
int dp[301][2];

void BottomUp()
{
    // 시작 - 첫 계단
    dp[1][0] = stairs[1];

    dp[2][0] = dp[1][0] + stairs[2];
    dp[2][1] = stairs[2];

    for(int i = 3; i <= n; i++)
    {
        // i 도착할 때 원 스텝으로 왔고, 연속 계단이 첫 번째인 경우
        // 직전에 투 스텝으로 온 것만 가능
        dp[i][0] = dp[i-1][1] + stairs[i];

        // i 도착할 때 투 스텝으로 오는 경우
        // 두 칸 전에 원 스텝으로 왔거나
        // 두 칸 전에 투 스텝으로 온 것
        // 중 더 큰 값
        dp[i][1] = max(dp[i-2][0], dp[i-2][1]) + stairs[i];
    }

    int ans = max(dp[n][0], dp[n][1]);

    cout << ans << "\n";
}

// int TopDown()
// {

// }

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        cin >> stairs[i];
    }

    BottomUp();

    // int ans = TopDown();
    // cout << ans << "\n";

    return 0;
}
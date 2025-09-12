#include <bits/stdc++.h>

using namespace std;

int n, m;

bool isVIP[41]; // VIP 표시

// dp[i] : 좌석이 i 일떄 앉을 수 있는 모든 경우의 수
int dp[41];

int ans = 1;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    // VIP 회원
    for(int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        
        isVIP[x] = true;
    }


    // dp 진행
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for(int i = 3; i <= n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }

    // vip - vip 사이의 좌석 수에서 앉을수 있는 경우의 수를 각각 곱하면 정답!
    int st = 1;
    int en = 1;
    for(en = 1; en <= n; en++)
    {
        if(isVIP[en])
        {
            ans *= dp[en - st];
            st = en + 1;
        }
    }

    ans *= dp[n - st + 1];

    cout << ans << "\n";

    return 0;
}
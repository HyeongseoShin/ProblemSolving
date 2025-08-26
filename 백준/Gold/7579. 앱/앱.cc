#include <bits/stdc++.h>

using namespace std;

#define MAX 10001
int n, m;

int bytes[101]; // 사용하고 있는 메모리
int c[101]; // 비활성화할 때 비용

int dp[101][MAX]; // dp[i][j] : i까지 봤고, j만큼 비활성화 비용 썼을 때 만들 수 있는 최대 바이트 크기

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    // 입력
    for(int i = 1; i <= n; i++) cin >> bytes[i];
    for(int i = 1; i <= n; i++) cin >> c[i];

    // DP-Knapsack 진행
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < MAX; j++)
        {
            if(c[i] <= j)
            {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j - c[i]] + bytes[i]);
            }
            else dp[i][j] = dp[i-1][j];
        }
    }

    // 정답 출력
    for(int i = 0; i < MAX; i++)
    {
        if(dp[n][i] >= m)
        {
            cout << i << "\n";
            break;
        } 
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int n, m;

long long dp[1005][1005]; // dp[i][j] : (i,j)까지 왔을 때 최댓값
long long l[1005][1005];
long long r[1005][1005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> dp[i][j];
            r[i][j] = l[i][j] = dp[i][j];
        }
    }


    // 0번째 행은 무조건 왼쪽에서 오는 것만 가능
    for(int i = 1; i < m; i++)
    {
        dp[0][i] += dp[0][i-1];
    }

    // 1번째 행부터는 왼쪽에서부터 오는 값 vs 오른쪽에서부터 오는 값 비교 후 더 큰 값 선택
    
    for(int i = 1; i < n; i++)
    {
        r[i][m-1] = dp[i-1][m-1] + dp[i][m-1];
        for(int j = m-2; j >= 0; j--)
        {
            // 왼쪽, 오른쪽으로 순회중 위쪽 값과 비교해 더 큰 값을 저장
            r[i][j] = max(r[i][j + 1], dp[i-1][j]) + dp[i][j];
        }

        l[i][0] = dp[i-1][0] + dp[i][0];
        for(int j = 1; j < m; j++)
        {
            // 왼쪽, 오른쪽으로 순회중 위쪽 값과 비교해 더 큰 값을 저장
            l[i][j] = max(l[i][j - 1], dp[i-1][j]) + dp[i][j];
        }

        for(int j = 0; j < m; j++)
        {
            dp[i][j] = max(l[i][j], r[i][j]);
        }
    }



    // for(int i = 0; i < n; i++)
    // {
    //     for(int j = 0; j < m; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    cout << dp[n-1][m-1] << "\n";

    return 0;
}
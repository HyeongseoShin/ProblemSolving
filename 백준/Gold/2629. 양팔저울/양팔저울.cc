// https://www.acmicpc.net/problem/2629

// 분류 : DP, 냅색

#include <bits/stdc++.h>

using namespace std;

int n, m;

int choo[31];

// dp[i][j] : i번째 추까지 봤을 때 j무게인 구슬을 측정할 수 있는지 없는지
bool dp[31][15001];

int sum = 0; // 전체 추의 무게

// 추 순회하며 측정 가능한 구슬 표시
void GetAns()
{
    // 추 순회
    for(int i = 1; i <= n; i++)
    {
        int cur = choo[i];
        dp[i][cur] = true; // 현재 추 무게의 구슬 측정 가능

        for(int j = 1; j <= sum; j++)
        {
            if(j - cur >= 0)
            {
                if(dp[i-1][j - cur] == true) // 현재 추를 이용해 j 무게의 추를 만들 수 있다면
                {
                    dp[i][j] = true;
                }
            }

            if(dp[i-1][j] == true) // j의 무게가 이전에 만들어졌다면
            {
                dp[i][abs(j - cur)] = true; // 반대쪽에 놨을 경우
                dp[i][j] = true; // 이번에도 만들 수 있음
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        cin >> choo[i];
        sum += choo[i];
    }

    GetAns();

    cin >> m;

    for(int i = 0; i < m; i++)
    {
        int ball;
        cin >> ball;

        if(ball > 15000) cout << "N\n";
        else if(dp[n][ball]) cout << "Y\n";
        else cout << "N\n";
    }

    return 0;
}
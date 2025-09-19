// https://www.acmicpc.net/problem/1563

// 분류 : DP

// 스스로 못 풂

// 참고 : https://kibbomi.tistory.com/98

#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000

int n;

// dp[i][j][k] : i날짜까지 j번 지각 했고, k번 연속 결석했을 때 가능한 출결 정보의 개수
// 개근상 가능한 경우
// dp[n][0][0] : 0번 지각, 0번 결석
// dp[n][0][1] : 0번 지각, 1번 결석
// dp[n][0][2] : 0번 지각, 2번 결석

// dp[n][1][0] : 1번 지각, 0번 결석
// dp[n][1][1] : 1번 지각, 1번 결석
// dp[n][1][2] : 1번 지각, 2번 결석
int dp[1001][2][3];

// Top-Down DP : 재귀
// 보통 리턴 값 있음

// 메모이제이션 활용 : 가지치기로 경우의 수 줄이기
// Base Condition 확실히
int TopDown(int d, int l, int a)
{
    // 2번 지각하면 끝
    if(l == 2) return 0;

    // 3번 연속 지각하면 끝
    if(a == 3) return 0;

    // 날짜 지나면 끝
    if(d > n) return 1;

    int &ret = dp[d][l][a];

    // 이미 해당 상태 방문한 경우 있으면 가지치기 : 메모이제이션
    if(ret != -1) return ret;

    // 오늘 출석, 지각, 결석한 경우
    // 출석, 지각한 경우 연속 결석 횟수 초기화!
    ret = (TopDown(d + 1, l, 0) + TopDown(d + 1, l + 1, 0) + TopDown(d + 1, l, a+1)) % MOD;
    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    memset(dp, -1, sizeof(dp));
    int ans = TopDown(1, 0, 0);

    cout << ans << "\n";

    return 0;
}
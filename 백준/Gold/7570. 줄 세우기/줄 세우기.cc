#include <bits/stdc++.h>

using namespace std;

#define MAX 1000001

int n;

int pos[MAX]; // 해당 번호 학생의 현재 위치
int dp[MAX]; // dp[i] : 숫자 i까지 봤을 때 이미 번호 순서대로 올바른 순서로 배치된 수의 개수

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        
        pos[x] = i;
    }

    int ans = 1;
    dp[1] = 1;

    for(int i = 2; i <= n; i++)
    {
        if(pos[i] > pos[i-1]) dp[i] = dp[i-1] + 1;
        else dp[i] = 1;

        ans = max(ans, dp[i]);
    }

    cout << n - ans << "\n";

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define MAX 1000001

int n;

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

        dp[x] = dp[x-1] + 1;
    }

    int ans = *max_element(dp + 1, dp + n + 1);

    cout << n - ans << "\n";
    return 0;
}
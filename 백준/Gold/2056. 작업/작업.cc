#include <bits/stdc++.h>

using namespace std;

int n;

// 작업 별 걸리는 시간
int task[10001];

// 먼저 선행되어야할 작업 번호
vector<int> pre[10001];

// dp[i] : i번 작업이 끝나는 시간
int dp[10001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        cin >> task[i];

        int cnt;

        cin >> cnt;

        for(int j = 0; j < cnt; j++)
        {
            int x;
            cin >> x;

            pre[i].push_back(x);
        }
    }

    for(int i = 1; i <= n; i++)
    {
        // 선행 작업 없으면 그냥 시작
        if((int)pre[i].size() == 0) dp[i] = task[i];

        else
        {
            int maxFinTime = 0;
            for(int j = 0; j < (int)pre[i].size(); j++)
            {
                maxFinTime = max(maxFinTime, dp[pre[i][j]]);
            }

            dp[i] = maxFinTime + task[i];
        }
    }

    int ans = 0;

    for(int i = 1; i <= n; i++)
    {
        ans = max(ans, dp[i]);
    }

    cout << ans << "\n";

    return 0;
}
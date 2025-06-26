#include <bits/stdc++.h>

using namespace std;

#define MAX 100001
int c, n;

int price[21];
int customer[21];

// dp[i] : i원 썼을 때 늘릴 수 있는 최대 사람 수
int dp[MAX];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> c >> n;

    for(int i = 1; i <= n; i++)
    {
        cin >> price[i] >> customer[i];
    }

    for(int i = 1; i <= n; i++)
    {
        // 1 ~ 최대 비용까지 순회
        for(int j = 1; j <= MAX; j++)
        {
            if(j - price[i] >= 0)
            {
                dp[j] = max(dp[j], dp[j - price[i]] + customer[i]);
            }
        }
    }

    // 작은 액수부터 비교하며 c넘으면 정답!
    for(int i = 1; i <= MAX; i++)
    {
        if(dp[i] >= c)
        {
            cout << i << "\n";
            break;
        }
    }

    return 0;
}
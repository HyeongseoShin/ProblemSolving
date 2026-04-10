#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cstring>
#include <queue>

using namespace std;

int n, m;

int ans[101];

int inDegree[101];

// dp[i][j] : i를 만드는 데 필요한 j 부품 개수
int dp[101][101];

// adj[i]: <완성 부품, 개수> -> i 부품 ~ 개수 써서 완성 부품 만듦
vector<pair<int, int>> adj[101];
queue<int> q;

void getAns()
{
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        for(auto [nxt, cnt] : adj[cur])
        {
            for(int i = 1; i <= n; i++)
            {
                dp[nxt][i] += (dp[cur][i] * cnt);
            }

            inDegree[nxt]--;
            if(inDegree[nxt] == 0) q.push(nxt);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        int x, y, k;
        cin >> x >> y >> k;

        // 그래프 뒤집기
        // 기본 -> 중간 -> 완성품
        adj[y].push_back({x, k});
        inDegree[x]++;
    }

    // 기본 부품 삽입
    for(int i = 1; i < n; i++)
    {
        if(inDegree[i] == 0)
        {
            dp[i][i] = 1;
            q.push(i);
        }
    }

    getAns();

    for(int i = 1; i < n; i++)
    {
        if(dp[n][i] > 0) cout << i << " " << dp[n][i] << "\n";
    }

    return 0;
}
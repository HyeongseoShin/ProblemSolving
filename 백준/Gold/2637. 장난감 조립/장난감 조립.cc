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

// adj[i]: <필요 부품, 개수>
vector<pair<int, int>> parts[101];

bool isBasic[101];

bool vis[101];

void solve(int cur)
{
    if(vis[cur]) return;
    vis[cur] = true;

    // 기본 부품
    if(isBasic[cur])
    {
        dp[cur][cur] = 1;
        return;
    }

    for(auto [nxt, cnt] : parts[cur])
    {
        solve(nxt);

        for(int i = 1; i <= n; i++)
        {
            dp[cur][i] += dp[nxt][i] * cnt;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    memset(isBasic, true, sizeof(isBasic));
    for(int i = 0; i < m; i++)
    {
        int x, y, k;
        cin >> x >> y >> k;

        parts[x].push_back({y, k});
        isBasic[x] = false;
    }

    solve(n);

    for(int i = 1; i < n; i++)
    {
        if(isBasic[i]) cout << i << " " << dp[n][i] << "\n";
    }

    return 0;
}
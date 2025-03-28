#include <bits/stdc++.h>

using namespace std;

int n, k;

int dst[15][15];

int ans = 100005;

bool vis[15];

// 현재 위치, 현재까지의 거리, 거쳐온 횟수
void DFS(int x, int curDist, int cnt)
{
    if(cnt == n - 1)
    {
        ans = min(ans, curDist);
        return;
    }

    vis[x] = true;

    for(int i = 0; i < n; i++)
    {
        if(vis[i]) continue;
        DFS(i, curDist + dst[x][i], cnt + 1);
        vis[i] = false;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> dst[i][j];
        }
    }

    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(dst[i][j] > dst[i][k] + dst[k][j])
                {
                    dst[i][j] = dst[i][k] + dst[k][j];
                }
            }
        }
    }

    // 현재 위치, 현재까지의 거리, 거쳐온 횟수
    DFS(k, 0, 0);

    cout << ans << "\n";

    return 0;
}
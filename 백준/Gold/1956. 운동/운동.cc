#include <bits/stdc++.h>

using namespace std;

int n, m;

int ans = INT_MAX;

int dist[401][401];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            dist[i][j] = INT_MAX;
        }
    }

    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = c;
    }

    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                // 길 없으면 패스
                if(dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) continue;

                if(dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }   
            }
        }
    }

    for(int i = 1; i <= n; i++) ans = min(ans, dist[i][i]);
    if(ans == INT_MAX) ans = -1;

    cout << ans << "\n";

    return 0;
}
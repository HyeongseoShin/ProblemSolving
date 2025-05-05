#include <bits/stdc++.h>

using namespace std;

int n, m;

int shark[50][50];

int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

int dist[50][50];

bool vis[50][50];

int ans = 0;

void BFS(int x, int y)
{
    queue<tuple<int, int, int>> q;

    q.push({x, y, 0});

    vis[x][y] = true;

    while(!q.empty())
    {
        auto [curX, curY, distance] = q.front();
        q.pop();

        if(shark[curX][curY] == 1)
        {
            dist[x][y] = min(dist[x][y], distance);
        }

        for(int i = 0; i < 8; i++)
        {
            int nX = curX + dx[i];
            int nY = curY + dy[i];

            if(nX < 0 || nX >= n || nY < 0 || nY >= m) continue;
            if(vis[nX][nY]) continue;

            vis[nX][nY] = true;
            q.push({nX, nY, distance + 1});
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> shark[i][j];
            dist[i][j] = 100;
        }
    }

    

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            memset(vis, false, sizeof(vis));
            BFS(i, j);
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            ans = max(ans, dist[i][j]);
        }
    }

    cout << ans << "\n";

    return 0;
}
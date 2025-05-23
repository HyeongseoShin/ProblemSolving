#include <bits/stdc++.h>

using namespace std;

int n, m, h;

int board[100][100][100];

queue<tuple<int, int, int>> q;

int dist[100][100][100];

int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

int ans = 0;

void BFS()
{
    while(!q.empty())
    {
        auto [curX, curY, curZ] = q.front();
        q.pop();

        for(int i = 0; i < 6; i++)
        {
            int nX = curX + dx[i];
            int nY = curY + dy[i];
            int nZ = curZ + dz[i];

            if(nX < 0 || nX >= n || nY < 0 || nY >= m || nZ < 0 || nZ >= h) continue;
            if(board[nX][nY][nZ] == -1) continue;
            if(dist[nX][nY][nZ] != INT_MAX) continue;

            dist[nX][nY][nZ] = dist[curX][curY][curZ] + 1;
            ans = max(ans, dist[nX][nY][nZ]);

            board[nX][nY][nZ] = 1;
            q.push({nX, nY, nZ});
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> h;

    for(int k = 0; k < h; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                cin >> board[i][j][k];

                dist[i][j][k] = INT_MAX;

                if(board[i][j][k] == 1)
                {
                    q.push({i, j, k});
                    dist[i][j][k] = 0;
                }
            }
        }
    }

    BFS();

    for(int k = 0; k < h; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(board[i][j][k] == 0)
                {
                    ans = -1;
                    break;
                }
            }

            if(ans == -1) break;
        }

        if(ans == -1) break;
    }

    cout << ans << "\n";

    return 0;
}
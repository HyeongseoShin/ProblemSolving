#include <bits/stdc++.h>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int h, w;

int dist[51][51];
char board[51][51];
int ans = 0;

void BFS(int x, int y)
{
    memset(dist, -1, sizeof(dist));

    queue<pair<int, int>> q;
    q.push({x, y});
    dist[x][y] = 0;

    while(!q.empty())
    {
        auto [curX, curY] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nX = curX + dx[i];
            int nY = curY + dy[i];

            if(nX < 0 || nX >= h || nY < 0 || nY >= w) continue;
            if(board[nX][nY] == 'W') continue;
            if(dist[nX][nY] != -1) continue;

            dist[nX][nY] = dist[curX][curY] + 1;

            ans = max(ans, dist[nX][nY]);

            q.push({nX, nY});
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> h >> w;

    for(int i = 0; i < h; i++)
    {
        string s;
        cin >> s;

        for(int j = 0; j < w; j++)
        {
            board[i][j] = s[j];
        }
    }

    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            if(board[i][j] == 'L') BFS(i, j);
        }
    }

    // for(int i = 0; i < h; i++)
    // {
    //     for(int j = 0; j < w; j++)
    //     {
    //         cout << setw(5) << dist[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    cout << ans << "\n";

    return 0;
}
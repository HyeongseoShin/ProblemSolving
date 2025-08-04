#include <bits/stdc++.h>

using namespace std;

int k;
int h, w;

int board[201][201];

int dist[201][201][50];

// 원숭이 이동
int mX[4] = {-1, 1, 0, 0};
int mY[4] = {0, 0, -1, 1};

// 말 이동
int hX[8] = {-2, -1, -2, -1, 2, 1, 2, 1};
int hY[8] = {-1, -2, 1, 2, 1, 2, -1, -2};

void BFS()
{
    queue<tuple<int, int, int>> q;

    dist[0][0][0] = 0;
    q.push({0, 0, dist[0][0][0]});

    while(!q.empty())
    {
        auto [curX, curY, curHorse] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nX = curX + mX[i];
            int nY = curY + mY[i];

            if(nX < 0 || nX >= h || nY < 0 || nY >= w) continue;
            if(board[nX][nY] == 1) continue;

            if(dist[nX][nY][curHorse] > dist[curX][curY][curHorse] + 1)
            {
                dist[nX][nY][curHorse] = dist[curX][curY][curHorse] + 1;
                q.push({nX, nY, curHorse});
            }
        }

        if(curHorse < k)
        {
            for(int i = 0; i < 8; i++)
            {
                int nX = curX + hX[i];
                int nY = curY + hY[i];

                if(nX < 0 || nX >= h || nY < 0 || nY >= w) continue;
                if(board[nX][nY] == 1) continue;

                if(dist[nX][nY][curHorse + 1] > dist[curX][curY][curHorse] + 1)
                {
                    dist[nX][nY][curHorse + 1] = dist[curX][curY][curHorse] + 1;
                    q.push({nX, nY, curHorse + 1});
                }
            }
        }
    }

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k;
    cin >> w >> h;

    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            cin >> board[i][j];            
        }
    }

    // dist 초기화
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            for(int l = 0; l <= k; l++)
            {
                dist[i][j][l] = INT_MAX;
            }
        }
    }

    BFS();

    int ans = INT_MAX;
    for(int i = 0; i <= k; i++)
    {
        ans = min(ans, dist[h-1][w-1][i]);
    }

    if(ans == INT_MAX) ans = -1;

    cout << ans << "\n";

    return 0;
}
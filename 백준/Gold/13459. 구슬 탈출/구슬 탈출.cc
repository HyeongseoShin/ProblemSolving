#include <bits/stdc++.h>

using namespace std;

char board[11][11];

int n, m;
int rX, rY, bX, bY;

bool vis[11][11][11][11]; // 빨간 공 위치, 파란 공 위치 방문 여부

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int ans = 0;

pair<int, int> moveBall(int x, int y, int d)
{
    while(true)
    {
        int nX = x + dx[d];
        int nY = y + dy[d];

        // 다음 칸이 벽이면 여기서 멈춰야 함
        if(board[nX][nY] == '#') break;

        x = nX;
        y = nY;

        // 구멍에 빠지면 멈춰야 함
        if(board[x][y] == 'O') break;
    }

    return {x, y};
}

void bfs()
{
    // <빨강X, 빨강Y, 파랑X, 파랑Y, 이동 횟수>
    queue<tuple<int, int, int, int, int>> q;
    q.push({rX, rY, bX, bY, 0});

    vis[rX][rY][bX][bY] = true;

    while(!q.empty())
    {
        auto [cRx, cRy, cBx, cBy, cnt] = q.front();
        q.pop();

        if(cnt >= 10) continue;

        for(int i = 0; i < 4; i++)
        {
            auto [nRx, nRy] = moveBall(cRx, cRy, i);
            auto [nBx, nBy] = moveBall(cBx, cBy, i);

            // 파란색 빠지면 실패
            if(board[nBx][nBy] == 'O') continue;

            // 빨간색만 빠지면 끝
            else if(board[nRx][nRy] == 'O')
            {
                ans = 1;
                return;
            }

            // 빨간공, 파란공이 겹치면
            // 더 많이 이동한 공을 한 칸 뒤로 보낸다.
            if(nRx == nBx && nRy == nBy)
            {
                int rDist = abs(cRx - nRx) + abs(cRy - nRy);
                int bDist = abs(cBx - nBx) + abs(cBy - nBy);

                if(rDist > bDist)
                {
                    nRx -= dx[i];
                    nRy -= dy[i];
                }

                else
                {
                    nBx -= dx[i];
                    nBy -= dy[i];
                }
            }

            // 이미 방문했으면 패스
            if(vis[nRx][nRy][nBx][nBy]) continue;

            vis[nRx][nRy][nBx][nBy] = true;
            q.push({nRx, nRy, nBx, nBy, cnt + 1});
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
        string s;
        cin >> s;

        for(int j = 0; j < m; j++)
        {
            board[i][j] = s[j];

            if(board[i][j] == 'R')
            {
                rX = i;
                rY = j;
                board[i][j] = '.';
            }

            else if(board[i][j] == 'B')
            {
                bX = i;
                bY = j;
                board[i][j] = '.';
            }
        }
    }

    bfs();

    cout << ans << "\n";

    return 0;
}
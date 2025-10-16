#include <bits/stdc++.h>

using namespace std;

string board[8];

int dx[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int dy[9] = {0, 0, 1, 1, 1, 0, -1, -1, -1};

bool vis[8][8][8];

// 현재 위치가 벽인지 검사
// x-t인 이유 : 내가 t 시간일 떄 (x, y)에 존재하니까 (x-t, y)에 벽이 있었다면 지금 (x, y)에 도달했기 때문에
bool isWall(int x, int y, int t)
{
    if(x - t < 0) return false;
    return board[x-t][y] == '#';
}

int BFS()
{
    // <x, y, 현재 시간>
    queue<tuple<int, int, int>> q;

    vis[7][0][0] = true;

    q.push({7, 0, 0});

    while(!q.empty())
    {
        auto [curX, curY, curT] = q.front();
        q.pop();

        if(curX == 0 && curY == 7) return 1;

        for(int i = 0; i < 9; i++)
        {
            int nX = curX + dx[i];
            int nY = curY + dy[i];
            int nT = min(curT + 1, 8);

            if(nX < 0 || nX >= 8 || nY < 0 || nY >= 8) continue; // 범위 넘으면 패스
            if(isWall(nX, nY, curT)) continue;
            if(isWall(nX, nY, nT)) continue;
            if(vis[nX][nY][nT]) continue;

            vis[nX][nY][nT] = true;
            q.push({nX, nY, nT});
        }
    }

    return 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 8; i++) cin >> board[i];

    cout << BFS() << "\n";

    return 0;
}
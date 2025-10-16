#include <bits/stdc++.h>

using namespace std;

string board[8];

int dx[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int dy[9] = {0, 0, 1, 1, 1, 0, -1, -1, -1};

// 해당 위치가 벽이 되는 시간
set<int> wallTime[8][8];

void printBoard()
{
    cout << "\n";
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int BFS()
{
    bool vis[8][8];
    memset(vis, false, sizeof(vis));

    // <x, y, 현재 시간>
    queue<tuple<int, int, int>> q;
    q.push({7, 0, 0});
    vis[7][0] = true;

    while(!q.empty())
    {
        auto [curX, curY, curT] = q.front();
        q.pop();

        for(int i = 0; i < 9; i++)
        {
            int nX = curX + dx[i];
            int nY = curY + dy[i];
            int nT = curT + 1;

            if(nX < 0 || nX >= 8 || nY < 0 || nY >= 8) continue; // 범위 넘으면 패스
            if(wallTime[nX][nY].count(nT) > 0 || wallTime[nX][nY].count(curT) > 0) continue; // 이동할 위치에 도착하는 시간에 벽이라면 패스

            // 도착점 도착 시 끝
            if(nX == 0 && nY == 7) return 1;

            // if(curT == 0) cout << "nX: " << nX << " nY: " << nY << " nT: " << nT << "\n";
            q.push({nX, nY, curT + 1});
        }
    }

    return 0;
}

// 좌표가 벽이 되는 시간을 저장
void moveWall(int t)
{
    for(int i = 7; i >= 0; i--)
    {
        for(int j = 0; j < 8; j++)
        {
            // 벽이면 한 칸 내리기
            if(board[i][j] == '#')
            {
                if(i == 7) board[i][j] = '.';
                else
                {
                    board[i][j] = '.';
                    board[i+1][j] = '#';
                    wallTime[i+1][j].insert(t);
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 8; i++)
    {
        cin >> board[i];
        for(int j = 0; j < 8; j++)
        {
            if(board[i][j] == '#') wallTime[i][j].insert(0);
        }
    }

    for(int i = 1; i <= 8; i++) moveWall(i);

    cout << BFS() << "\n";

    return 0;
}
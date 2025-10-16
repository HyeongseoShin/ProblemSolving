#include <bits/stdc++.h>

using namespace std;

string board[8];

int dx[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int dy[9] = {0, 0, 1, 1, 1, 0, -1, -1, -1};

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

// 벽 이동
void moveWall()
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
                }
            }
        }
    }
}

int BFS()
{
    // <x, y, 현재 시간>
    queue<tuple<int, int>> q;
    q.push({7, 0});

    while(!q.empty())
    {
        int sz = (int)q.size();

        while(sz--)
        {
            auto [curX, curY] = q.front();
            q.pop();

            if(board[curX][curY] == '#') continue;

            for(int i = 0; i < 9; i++)
            {
                int nX = curX + dx[i];
                int nY = curY + dy[i];

                if(nX < 0 || nX >= 8 || nY < 0 || nY >= 8) continue; // 범위 넘으면 패스
                if(board[nX][nY] == '#') continue;

                // 도착점 도착 시 끝
                if(nX == 0 && nY == 7) return 1;

                q.push({nX, nY});
            }
        }

        moveWall();
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
#include <bits/stdc++.h>

using namespace std;

int r, c;

int board[51][51];

int t;

// airStart : 공청기 위, airEnd : 공청기 아래
int airStart = -1, airEnd = -1;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void CleanBFS()
{
    // 반시계 방향
    int stX = airStart - 1, stY = 0;

    // 아래
    while(stX > 0)
    {
        board[stX][stY] = board[stX-1][stY];
        stX--;
    }
    board[stX][stY] = 0;

    // 왼쪽
    while(stY < c - 1)
    {
        board[stX][stY] = board[stX][stY + 1];
        stY++;
    }
    board[stX][stY] = 0;

    // 위쪽
    while(stX < airStart)
    {
        board[stX][stY] = board[stX + 1][stY];
        stX++;
    }
    board[stX][stY] = 0;

    // 오른쪽
    while(stY > 1)
    {
        board[stX][stY] = board[stX][stY-1];
        stY--;
    }
    board[stX][stY] = 0;

    // 시계 방향
    stX = airEnd + 1, stY = 0;

    // 위
    while(stX < r - 1)
    {
        board[stX][stY] = board[stX+1][stY];
        stX++;
    }
    board[stX][stY] = 0;

    // 왼쪽
    while(stY < c - 1)
    {
        board[stX][stY] = board[stX][stY + 1];
        stY++;
    }
    board[stX][stY] = 0;

    // 아래쪽
    while(stX > airEnd)
    {
        board[stX][stY] = board[stX-1][stY];
        stX--;
    }
    board[stX][stY] = 0;

    // 오른쪽
    while(stY > 1)
    {
        board[stX][stY] = board[stX][stY-1];
        stY--;
    }
    board[stX][stY] = 0;
}

void BFS()
{
    queue<pair<int, int>> q;
    
    // 미세먼지 있는 칸 구하기
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(board[i][j] <= 0) continue;
            q.push({i, j});
        }
    }

    int tmp[51][51];
    memset(tmp, 0, sizeof(tmp));

    // 확산
    while(!q.empty())
    {
        auto [curX, curY] = q.front();
        q.pop();

        int tmpVal = board[curX][curY];
        for(int i = 0; i < 4; i++)
        {
            int nX = curX + dx[i];
            int nY = curY + dy[i];

            if(nX < 0 || nX >= r || nY < 0 || nY >= c) continue;
            if(board[nX][nY] == -1) continue;

            tmp[nX][nY] += (tmpVal / 5);
            board[curX][curY] -= (tmpVal / 5);
        }
    }

    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c ; j++)
        {
            board[i][j] += tmp[i][j];
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c >> t;

    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            cin >> board[i][j];

            if(board[i][j] == -1)
            {
                if(airStart == -1) airStart = i;
                else airEnd = i;
            }
        }
    }

    while(t--)
    {
        // 미세먼지 확산
        BFS();

        // 공청기 작동
        CleanBFS();

        // cout << "\n==========================\n";

        // for(int i = 0; i < r; i++)
        // {
        //     for(int j = 0; j < c; j++)
        //     {
        //         cout << board[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

        // cout << "\n==========================\n";
    }

    int ans = 0;
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(board[i][j] > 0) ans += board[i][j];
        }
    }

    cout << ans << "\n";

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int board[51][51];

int n, m;

int robotX, robotY, robotD;

bool vis[51][51];

int ans = 0;

void GetAns(int x, int y, int dir)
{
    while(true)
    {
        if(!vis[x][y])
        {
            vis[x][y] = true; // 현재 칸 청소
            ans++;
        }

        bool isMoved = false;
        for(int i = 0; i < 4; i++)
        {
            dir = (dir + 3) % 4;
            int nX = x + dx[dir];
            int nY = y + dy[dir];

            if(nX < 0 || nX >= n || nY < 0 || nY >= m) continue;
            if(vis[nX][nY]) continue;
            if(board[nX][nY] == 1) continue;

            x = nX;
            y = nY;
            isMoved = true;
            break;
        }

        if(isMoved) continue;

        int bX = x - dx[dir];
        int bY = y - dy[dir];

        if (bX < 0 || bX >= n || bY < 0 || bY >= m || board[bX][bY] == 1) break;
        
        x = bX;
        y = bY;
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    cin >> robotX >> robotY >> robotD;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }

    GetAns(robotX, robotY, robotD);

    cout << ans << "\n";

    return 0;
}
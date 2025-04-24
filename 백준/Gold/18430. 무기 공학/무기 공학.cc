#include <bits/stdc++.h>

using namespace std;

int n, m;

int board[10][10];
bool isUsed[10][10];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int ans = 0;

void GetAns(int x, int y, int cur)
{
    if(y == m)
    {
        x++;
        y = 0;
    }

    if(x == n)
    {
        ans = max(ans, cur);
        return;
    }

    if(!isUsed[x][y])
    {
        for(int i = 0; i < 4; i++)
        {
            int nX1 = x + dx[i];
            int nY1 = y + dy[i];

            int nX2 = x + dx[(i + 1) % 4];
            int nY2 = y + dy[(i + 1) % 4];

            if(nX1 < 0 || nX1 >= n || nY1 < 0 || nY1 >= m) continue;
            if(isUsed[nX1][nY1]) continue;

            if(nX2 < 0 || nX2 >= n || nY2 < 0 || nY2 >= m) continue;
            if(isUsed[nX2][nY2]) continue;

            isUsed[x][y] = true;
            isUsed[nX1][nY1] = true;
            isUsed[nX2][nY2] = true;

            GetAns(x, y + 1, cur + board[x][y] * 2 + board[nX1][nY1] + board[nX2][nY2]);

            isUsed[x][y] = false;
            isUsed[nX1][nY1] = false;
            isUsed[nX2][nY2] = false;

        }
    }
    

    GetAns(x, y + 1, cur);
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
            cin >> board[i][j];
        }
    }

    GetAns(0, 0, 0);

    cout << ans << "\n";


    return 0;
}
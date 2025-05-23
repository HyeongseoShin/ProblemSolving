#include <bits/stdc++.h>

using namespace std;

int n, m;

int board[505][505];

int ans = 0;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool vis[505][505];
void DFS(int x, int y, int cnt, int sum)
{
    if(cnt == 3)
    {
        ans = max(ans, sum);
        return;
    }

    for(int i = 0; i < 4; i++)
    {
        int nX = x + dx[i];
        int nY = y + dy[i];

        if(nX < 1 || nX > n || nY < 1 || nY > m) continue;
        if(vis[nX][nY]) continue;

        vis[nX][nY] = true;
        DFS(nX, nY, cnt + 1, sum + board[nX][nY]);
        vis[nX][nY] = false;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> board[i][j];
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            vis[i][j] = true;
            DFS(i, j, 0, board[i][j]);
            vis[i][j] = false;
        }
    }

    // T 예외 처리
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            int sum1 = board[i][j] + board[i-1][j] + board[i+1][j] + board[i][j+1];
            int sum2 = board[i][j] + board[i-1][j] + board[i+1][j] + board[i][j-1];
            int sum3 = board[i][j] + board[i-1][j] + board[i][j-1] + board[i][j+1];
            int sum4 = board[i][j] + board[i+1][j] + board[i][j-1] + board[i][j+1];

            ans = max({ans, sum1, sum2, sum3, sum4});
        }
    }

    cout << ans << "\n";

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int m, n;
int board[501][501];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// dp[i][j] : (i, j) ~ (n - 1, m - 1)까지 가능한 내리막 길 경로의 개수
int dp[501][501];

int DFS(int x, int y)
{
    // 도착
    if(x == m - 1 && y == n - 1) return 1;

    // 방문 했던 곳이면 Return
    if(dp[x][y] != -1) return dp[x][y];

    dp[x][y] = 0;

    for(int i = 0; i < 4; i++)
    {
        int nX = x + dx[i];
        int nY = y + dy[i];

        if(nX < 0 || nX >= m || nY < 0 || nY >= n) continue;
        if(board[x][y] <= board[nX][nY]) continue;
        
        dp[x][y] += DFS(nX, nY);
    }

    return dp[x][y];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> board[i][j];
            dp[i][j] = -1;
        }
    }

    int ans = DFS(0, 0);

    cout << ans << "\n";

    return 0;
}
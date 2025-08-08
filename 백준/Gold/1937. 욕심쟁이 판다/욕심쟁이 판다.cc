#include <bits/stdc++.h>

using namespace std;

int n;

int board[501][501];
int dp[501][501];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int ans = 1;

int DFS(int x, int y)
{
    if(dp[x][y] != 0) return dp[x][y];
    dp[x][y] = 1;

    for(int i = 0; i < 4; i++)
    {
        int nX = x + dx[i];
        int nY = y + dy[i];

        if(nX < 0 || nX >= n || nY < 0 || nY >= n) continue;
        if(board[nX][nY] <= board[x][y]) continue;

        dp[x][y] = max(dp[x][y], DFS(nX, nY) + 1);
        
    }

    return dp[x][y];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }

    for(int i = 0; i < n; i++) 
    {
        for(int j = 0; j < n; j++)
        {
            ans = max(ans, DFS(i, j));
        }
    }

    cout << ans << "\n";

    return 0;
}
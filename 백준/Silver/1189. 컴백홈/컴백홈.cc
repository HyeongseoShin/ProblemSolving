#include <bits/stdc++.h>

using namespace std;

int r, c, k;

char board[6][6];

int ans = 0;

bool vis[6][6];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void DFS(int x, int y, int dist)
{
    if(x == 0 && y == c - 1)
    {
        if(dist == k) ans++;
        return;
    }

    for(int i = 0; i < 4; i++)
    {
        int nX = x + dx[i];
        int nY = y + dy[i];

        if(nX < 0 || nX >= r || nY < 0 || nY >= c) continue;
        if(board[nX][nY] == 'T') continue;
        if(vis[nX][nY]) continue;

        vis[nX][nY] = true;
        DFS(nX, nY, dist + 1);
        vis[nX][nY] = false;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c >> k;

    for(int i = 0; i < r; i++)
    {
        string s;
        cin >> s;
        for(int j = 0; j < c; j++)
        {
            board[i][j] = s[j];
        }
    }

    vis[r-1][0] = true;
    DFS(r-1, 0, 1);

    cout << ans << "\n";

    return 0;
}
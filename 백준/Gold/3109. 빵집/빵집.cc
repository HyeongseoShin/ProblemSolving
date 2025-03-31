#include <bits/stdc++.h>

using namespace std;

int r, c;

char board[10005][505];

int dx[3] = {-1, 0, 1};
int dy[3] = {1, 1, 1};

bool vis[10005][505];

int ans = 0;
bool isFinish = false;

void DFS(int x, int y)
{
    vis[x][y] = true;

    if(y == c - 1)
    {
        ans++;
        isFinish = true;
        return;
    }

    for(int i = 0; i < 3; i++)
    {
        int nX = x + dx[i];
        int nY = y + dy[i];

        if(isFinish) continue;
        if(nX < 0 || nX >= r || nY < 0 || nY >= c) continue;
        if(board[nX][nY] == 'x') continue;
        if(vis[nX][nY]) continue;

        DFS(nX, nY);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c;

    for(int i = 0; i < r; i++)
    {
        string s;
        cin >> s;
        for(int j = 0; j < c; j++)
        {
            board[i][j] = s[j];
        }
    }

    for(int k = 0; k < r; k++)
    {
        isFinish = false;
        DFS(k, 0);

        
    }

    

    cout << ans << "\n";

    return 0;
}
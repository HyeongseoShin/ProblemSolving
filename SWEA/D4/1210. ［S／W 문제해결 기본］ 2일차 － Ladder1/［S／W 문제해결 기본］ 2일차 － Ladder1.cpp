#include <bits/stdc++.h>

using namespace std;

int board[100][100];

int enX, enY;

bool vis[100][100];

int dx[3] = {0, 0, -1};
int dy[3] = {1, -1, 0};

int ans = 0;
bool isFinished = false;
void DFS(int x, int y)
{
    if(x == 0)
    {
        ans = y;
        isFinished = true;
        return;
    }

    for(int i = 0; i < 3; i++)
    {
        if(isFinished) continue;
        int nX = x + dx[i];
        int nY = y + dy[i];

        if(nX < 0 || nX >= 100 | nY < 0 || nY >= 100) continue;
        if(board[nX][nY] == 0) continue;
        if(vis[nX][nY]) continue;

        vis[nX][nY] = true;
        DFS(nX, nY);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int t = 1; t <= 10; t++)
    {
        int n;
        cin >> n;

        for(int i = 0; i < 100; i++)
        {
            for(int j = 0; j < 100; j++)
            {
                cin >> board[i][j];

                if(board[i][j] == 2)
                {
                    enX = i;
                    enY = j;
                }
            }
        }

        memset(vis, false, sizeof(vis));
        vis[enX][enY] = true;
        isFinished = false;
        DFS(enX, enY);

        cout << "#" << n << " " << ans << "\n";
    }
    
    return 0;
}
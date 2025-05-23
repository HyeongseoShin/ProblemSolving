#include <bits/stdc++.h>

using namespace std;

int n, m;

int board[8][8];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int ans = 0;

void BFS()
{
    queue<pair<int, int>> q;
    
    bool vis[8][8];
    memset(vis, false, sizeof(vis));

    int tmp[8][8];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            tmp[i][j] = board[i][j];

            if(tmp[i][j] == 2)
            {
                q.push({i, j});
                vis[i][j] = true;
            }
        }
    }

    while(!q.empty())
    {
        auto [curX, curY] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nX = curX + dx[i];
            int nY = curY + dy[i];

            if(nX < 0 || nX >= n || nY < 0 || nY >= m) continue;
            if(tmp[nX][nY] != 0) continue;
            if(vis[nX][nY]) continue;            

            vis[nX][nY] = true;
            tmp[nX][nY] = 2;

            q.push({nX, nY});
        }
    }

    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(tmp[i][j] == 0) cnt++;
        }
    }

    ans = max(ans, cnt);
}

void MakeWall(int cnt)
{
    if(cnt == 3)
    {
        BFS();
        return;
    }

    // 벽 설치
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(board[i][j] == 0)
            {
                board[i][j] = 1;
                MakeWall(cnt + 1);
                board[i][j] = 0;
            }
        }
    }
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

    MakeWall(0);

    cout << ans << "\n";
    
    return 0;
}
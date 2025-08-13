#include <bits/stdc++.h>

using namespace std;

int n;
int board[101][101];

int island[101][101];
bool vis[101][101];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int no = 1;

int ans = INT_MAX;

queue<pair<int, int>> outPos;

void BFS(int x, int y)
{
    queue<pair<int,int>> q;
    q.push({x, y});
    vis[x][y] = true;
    island[x][y] = no;

    while(!q.empty())
    {
        auto [curX, curY] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nX = curX + dx[i];
            int nY = curY + dy[i];

            if(nX < 0 || nX >= n || nY < 0 || nY >= n) continue;
            if(board[nX][nY] == 0) continue;
            if(vis[nX][nY]) continue;

            vis[nX][nY] = true;
            island[nX][nY] = no;
            q.push({nX, nY});
        }

    }
}

bool CheckBounds(int x, int y)
{
    for(int i = 0; i < 4; i++)
    {
        int nX = x + dx[i];
        int nY = y + dy[i];

        if(nX < 0 || nX >= n || nY < 0 || nY >= n) continue;
        if(island[nX][nY] == 0) return true;
    }

    return false;

}

int FindShortestBridge(int num)
{
    queue<pair<int, int>> q;
    int depth = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(island[i][j] == num)
            {
                q.push({i, j});
                vis[i][j] = true;
            }
        }
    }

    while(!q.empty())
    {
        int qs = q.size();
        while(qs--)
        {
            auto [curX, curY] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++)
            {
                int nX = curX + dx[i];
                int nY = curY + dy[i];

                if(nX < 0 || nX >= n || nY < 0 || nY >= n) continue;
                if(island[nX][nY] != 0 && island[nX][nY] != num) return depth;
                if(vis[nX][nY]) continue;

                vis[nX][nY] = true;
                q.push({nX, nY});
            }
        }

        depth++;
    }

    return depth;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n ;j++)
        {
            cin >> board[i][j];
        }
    }

    // 섬에 번호 부여
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(board[i][j] == 0) continue;
            if(vis[i][j]) continue;

            BFS(i, j);
            no++;
        }
    }

    for(int i = 1; i < no; i++)
    {
        ans = min(ans, FindShortestBridge(i));
        memset(vis, false, sizeof(vis));
    }

    cout << ans << "\n";

    return 0;
}
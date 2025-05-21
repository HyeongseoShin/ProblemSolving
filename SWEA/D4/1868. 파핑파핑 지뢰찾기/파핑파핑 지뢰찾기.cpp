#include <bits/stdc++.h>

using namespace std;

int n;

char board[306][306];
bool vis[306][306];

int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

// 주위 8칸에 지뢰가 있느지 확인
bool IsNearBomb(int x, int y)
{
    for(int dir = 0; dir < 8; dir++)
    {
        int nX = x + dx[dir];
        int nY = y + dy[dir];

        if(nX < 0 || nX >= n || nY < 0 || nY >= n) continue;
        if(vis[nX][nY]) continue;
        
        if(board[nX][nY] == '*') return true;
    }

    return false;
}

// BFS로 땅 open
void BFS(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});

    vis[x][y] = true;

    while(!q.empty())
    {
        auto [curX, curY] = q.front();
        q.pop();

        for(int dir = 0; dir < 8; dir++)
        {
            int nX = curX + dx[dir];
            int nY = curY + dy[dir];

            if(nX < 0 || nX >= n || nY < 0 || nY >= n) continue;
            if(vis[nX][nY]) continue;
            
            vis[nX][nY] = true;

            if(!IsNearBomb(nX, nY)) q.push({nX, nY});
        }
    }

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int testCase;
    cin >> testCase;

    for(int t = 1; t <= testCase; t++)
    {
        cin >> n;

        for(int i = 0; i < n; i++)
        {
            string s;
            cin >> s;

            for(int j = 0; j < n; j++)
            {
                board[i][j] = s[j];
            }
        }

        memset(vis, false, sizeof(vis));
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] == '*') continue;
                if(vis[i][j]) continue;
                if(IsNearBomb(i, j)) continue;

                BFS(i, j);
                ans++;
            }
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(!vis[i][j] && board[i][j] == '.') ans++;
            }
        }

        cout << "#" << t << " " << ans << "\n";
    }

    return 0;
}
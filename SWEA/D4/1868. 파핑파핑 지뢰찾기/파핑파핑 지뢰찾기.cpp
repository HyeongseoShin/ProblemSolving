#include <bits/stdc++.h>

using namespace std;

int n;
char board[301][301];
bool vis[301][301];

int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

int ans = 0;

// 해당 칸 주변 8칸에 지뢰가 있는지 확인
bool check(int x, int y)
{
    for(int i = 0; i < 8; i++)
    {
        int nX = x + dx[i];
        int nY = y + dy[i];

        if(nX < 0 || nX >= n || nY < 0 || nY >= n) continue;
        if(vis[nX][nY]) continue;

        if(board[nX][nY] == '*') return false;
    }

    return true;
}

// 주변 8칸 모두 지뢰 없는 칸 클릭하기 => 계속 확인하며 연쇄로 터트릴 수 있는지 확인
void BFS(int x, int y)
{
    ans++;
    queue<pair<int, int>> q;
    q.push({x, y});

    vis[x][y] = true;

    while(!q.empty())
    {
        auto [curX, curY] = q.front();
        q.pop();

        for(int i = 0; i < 8; i++)
        {
            int nX = curX + dx[i];
            int nY = curY + dy[i];

            if(nX < 0 || nX >= n || nY < 0 || nY >= n) continue;
            if(vis[nX][nY]) continue;

            vis[nX][nY] = true;

            // 연쇄로 터트릴 수 있는지 확인
            if(check(nX, nY)) q.push({nX, nY});
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
        ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] == '*') continue;
                if(vis[i][j]) continue;

                // 현재 칸 주변 8칸이 모두 지뢰가 아닌지 판별
                if(!check(i, j)) continue;

                BFS(i, j);
            }
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                // 현재 칸에 지뢰가 없지만 클릭한 적이 없다면 횟수++
                if(board[i][j] == '.' && !vis[i][j]) ans++;
            }
        }

        cout << "#" << t << " " << ans << "\n";
    }
    return 0;
}
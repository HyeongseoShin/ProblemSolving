#include <bits/stdc++.h>

using namespace std;

int n, m;

// 1 : 치즈, 0 : 빈칸
int board[101][101];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int ans = 0;
vector<int> cnt;
int cheeseCnt = 0;

void BFS()
{
    bool vis[101][101];

    memset(vis, false, sizeof(vis));

    vis[0][0] = true;

    queue<pair<int, int>> q;
    q.push({0, 0});

    while(!q.empty())
    {
        auto [curX, curY] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nX = curX + dx[i];
            int nY = curY + dy[i];

            if(nX < 0 || nX >= n || nY < 0 || nY >= m) continue;
            if(vis[nX][nY]) continue;

            vis[nX][nY] = true;

            if(board[nX][nY] == 1) continue;
            
            q.push({nX, nY});
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(board[i][j] == 1 && vis[i][j])
            {
                cheeseCnt--;
                board[i][j] = 0;
            }
        }
    }

    cnt.push_back(cheeseCnt);
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

            if(board[i][j] == 1) cheeseCnt++;
        }
    }

    cnt.push_back(cheeseCnt);

    while(cheeseCnt > 0)
    {
        BFS();
        ans++;
    }

    cout << ans << "\n";
    cout << cnt[ans-1] << "\n";

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

char board[16][16];

int stX, stY, enX, enY;

bool vis[16][16];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void BFS(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    vis[x][y] = true;

    while(!q.empty())
    {
        auto [curX, curY] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nX = curX + dx[i];
            int nY = curY + dy[i];

            if(nX < 0 || nX >= 16 || nY < 0 || nY >= 16) continue;
            if(board[nX][nY] == '1') continue;
            if(vis[nX][nY]) continue;

            vis[nX][nY] = true;
            q.push({nX, nY});
        }
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

        for(int i = 0; i < 16; i++)
        {
            string s;
            cin >> s;

            for(int j = 0; j < 16; j++)
            {
                board[i][j] = s[j];
                if(board[i][j] == '2')
                {
                    stX = i;
                    stY = j;
                }

                else if(board[i][j] == '3')
                {
                    enX = i;
                    enY = j;
                }
            }
        }

        memset(vis, false, sizeof(vis));
        BFS(stX, stY);

        cout << "#" << n << " ";
        if(vis[enX][enY]) cout << "1\n";
        else cout << "0\n";
    }
    return 0;
}
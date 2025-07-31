#include <bits/stdc++.h>

using namespace std;

int n, m;

int board[101][101];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool vis[101][101];
int cnt[101][101];

void BFS(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    cnt[x][y] = 0;

    while(!q.empty())
    {
        auto [curX, curY] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nX = curX + dx[i];
            int nY = curY + dy[i];

            if(nX < 0 || nX >= n || nY < 0 || nY >= m) continue;
            
            if(board[nX][nY] == 0 && cnt[nX][nY] > cnt[curX][curY])
            {
                cnt[nX][nY] = cnt[curX][curY];
                q.push({nX, nY});
            } 
            else if(board[nX][nY] == 1 && cnt[nX][nY] > cnt[curX][curY] + 1)
            {
                cnt[nX][nY] = cnt[curX][curY] + 1;
                q.push({nX, nY});
            }
            
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;

    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        for(int j = 0; j < m; j++)
        {
            board[i][j] = s[j] - '0';
            cnt[i][j] = INT_MAX;
        }
    }

    BFS(0, 0);

    // for(int i = 0; i < n; i++)
    // {
    //     for(int j = 0; j < m; j++)
    //     {
    //         cout << cnt[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    cout << cnt[n-1][m-1] << "\n";


    return 0;
}
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
    deque<pair<int, int>> dq;
    dq.push_back({x, y});
    cnt[x][y] = 0;

    while(!dq.empty())
    {
        auto [curX, curY] = dq.front();
        dq.pop_front();

        for(int i = 0; i < 4; i++)
        {
            int nX = curX + dx[i];
            int nY = curY + dy[i];

            if(nX < 0 || nX >= n || nY < 0 || nY >= m) continue;
            
            // cnt[curX][curY] : 현재까지 오는데 벽 부순 횟수
            // board[nX][nY] : 빈 공간이면 0, 벽이면 1
            int cost = cnt[curX][curY] + board[nX][nY];

            if(cnt[nX][nY] > cost)
            {
                cnt[nX][nY] = cost;

                if(board[nX][nY] == 0) dq.push_front({nX, nY});
                else dq.push_back({nX, nY});
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
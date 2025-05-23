#include <bits/stdc++.h>

using namespace std;

int board[1005][1005];
int n, m;

int stX, stY;

int dist[1005][1005];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void BFS()
{
    queue<pair<int, int>> q;
    q.push({stX, stY});

    dist[stX][stY] = 0;

    while(!q.empty())
    {
        auto [curX, curY] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nX = curX + dx[i];
            int nY = curY + dy[i];

            if(nX < 0 || nX >= n || nY < 0 || nY >= m) continue;
            if(board[nX][nY] == 0) continue;
            if(dist[nX][nY] != INT_MAX) continue;

            dist[nX][nY] = dist[curX][curY] + 1;
            q.push({nX, nY});
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

            if(board[i][j] == 2)
            {
                stX = i;
                stY = j;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            dist[i][j] = INT_MAX;
        }
    }

    BFS();

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(dist[i][j] == INT_MAX)
            {
                if(board[i][j] == 1) dist[i][j] = -1;
                else if(board[i][j] == 0) dist[i][j] = 0;
            }
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
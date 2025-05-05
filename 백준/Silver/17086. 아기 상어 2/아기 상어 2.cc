#include <bits/stdc++.h>

using namespace std;

int n, m;

int shark[50][50];

int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

int dist[50][50];

int ans = 0;

queue<pair<int, int>> q;

void BFS()
{
    while(!q.empty())
    {
        auto [curX, curY] = q.front();
        q.pop();
        
        for(int i = 0; i < 8; i++)
        {
            int nX = curX + dx[i];
            int nY = curY + dy[i];

            if(nX < 0 || nX >= n || nY < 0 || nY >= m) continue;
            
            if(dist[nX][nY] > dist[curX][curY] + 1)
            {
                dist[nX][nY] = dist[curX][curY] + 1;
                ans = max(ans, dist[nX][nY]);
                q.push({nX, nY});
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
            cin >> shark[i][j];

            dist[i][j] = INT_MAX;
            if(shark[i][j] == 1)
            {
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }

    BFS();

    cout << ans << "\n";

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int n, m;

char road[1005][1005];

// dp[i][j][0] : i, j 까지 오는 데에 벽을 부수지 않고 온 최단 경로
// dp[i][j][1] : i, j 까지 오는 데에 벽을 부수고 온 최단 경로
int dp[1005][1005][2];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void BFS(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});

    dp[x][y][0] = dp[x][y][1] = 1;

    while(!q.empty())
    {
        auto [curX, curY] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nX = curX + dx[i];
            int nY = curY + dy[i];

            if(nX < 0 || nX >= n || nY < 0 || nY >= m) continue;

            if(road[nX][nY] == '1')
            {
                if(dp[nX][nY][1] > dp[curX][curY][0] + 1)
                {
                    dp[nX][nY][1] = dp[curX][curY][0] + 1;
                    q.push({nX, nY});
                }
            }
            else
            {
                if(dp[nX][nY][0] > dp[curX][curY][0] + 1)
                {
                    dp[nX][nY][0] = dp[curX][curY][0] + 1;
                    q.push({nX, nY});
                }
                
                if(dp[nX][nY][1] > dp[curX][curY][1] + 1)
                {
                    dp[nX][nY][1] = dp[curX][curY][1] + 1;
                    q.push({nX, nY});
                }
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
        string s;
        cin >> s;

        for(int j = 0; j < m; j++)
        {   
            dp[i][j][0] = dp[i][j][1] = 1000001;
            road[i][j] = s[j];
        }
    }

    BFS(0, 0);

    if(dp[n-1][m-1][0] == 1000001 && dp[n-1][m-1][1] == 1000001) cout << "-1\n";
    else cout << min(dp[n-1][m-1][0], dp[n-1][m-1][1]) << "\n";

    return 0;
}
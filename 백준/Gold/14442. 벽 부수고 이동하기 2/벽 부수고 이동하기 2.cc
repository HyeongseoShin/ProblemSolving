// https://www.acmicpc.net/problem/14442

// 분류 : BFS

// 0% 틀렸습니다

#include <bits/stdc++.h>

using namespace std;

#define MAX 1000001

int n, m, k;

int board[1001][1001];

// dist[i][j][k] : (i,j)까지 오는데 벽을 k번 부쉈을 때 최소 경로
int dist[1001][1001][11];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void BFS()
{
    queue<pair<int, int>> q;
    q.push({0, 0});

    for(int i = 0; i <= k; i++) dist[0][0][i] = 1;

    while(!q.empty())
    {
        auto [curX, curY] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nX = curX + dx[i];
            int nY = curY + dy[i];

            // 경계값 넘어가면 pass
            if(nX < 0 || nX >= n || nY < 0 || nY >= m) continue;

            // 빈 칸이라면 그냥 진행
            if(board[nX][nY] == 0)
            {
                for(int j = 0; j <= k; j++)
                {
                    if(dist[nX][nY][j] > dist[curX][curY][j] + 1)
                    {
                        dist[nX][nY][j] = dist[curX][curY][j] + 1;
                        q.push({nX, nY});
                    }
                }
            }

            // 벽이라면
            else
            {
                for(int j = 1; j <= k; j++)
                {
                    if(dist[nX][nY][j] > dist[curX][curY][j-1] + 1)
                    {
                        dist[nX][nY][j] = dist[curX][curY][j-1] + 1;
                        q.push({nX, nY});
                    }
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        for(int j = 0; j < m; j++)
        {
            board[i][j] = s[j] - '0';
            
            // dist 배열 초기화
            for(int l = 0; l <= k; l++) dist[i][j][l] = MAX;
        }
    }

    BFS();

    int ans = MAX;

    for(int i = 0; i <= k; i++)
    {
        ans = min(ans, dist[n-1][m-1][i]);
    }

    if(ans == MAX) ans = -1;

    cout << ans << "\n";

    return 0;
}
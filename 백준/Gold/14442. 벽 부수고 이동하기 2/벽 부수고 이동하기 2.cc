#include <bits/stdc++.h>

using namespace std;

int n, m, k;

int board[1001][1001];

// dist[i][j][k] : (i,j)까지 오는데 벽을 k번 부쉈을 때 최소 경로
int dist[1001][1001][11];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int BFS()
{
    // <x좌표, y좌표, 벽 부순 횟수>
    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0});

    dist[0][0][0] = 1;

    while(!q.empty())
    {
        auto [curX, curY, broken] = q.front();
        q.pop();

        if(curX == n - 1 && curY == m - 1) return dist[curX][curY][broken];

        for(int i = 0; i < 4; i++)
        {
            int nX = curX + dx[i];
            int nY = curY + dy[i];

            // 경계값 넘어가면 pass
            if(nX < 0 || nX >= n || nY < 0 || nY >= m) continue;

            // 빈 칸이라면 그냥 진행
            if(board[nX][nY] == 0)
            {
                // 방문 확인
                if(dist[nX][nY][broken] != 0) continue;
                dist[nX][nY][broken] = dist[curX][curY][broken] + 1;
                q.push({nX, nY, broken});
                
            }

            // 벽이라면
            else
            {
                if(broken >= k) continue; // 이미 벽 부순 횟수 다 썼으면 pass
                if(dist[nX][nY][broken+1] != 0) continue; // 이미 방문했다면 pass
                
                dist[nX][nY][broken+1] = dist[curX][curY][broken] + 1;
                q.push({nX, nY, broken+1});
            }
        }
    }

    // 목표 지점 방문 못하면 -1 리턴
    return -1;
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
        }
    }

    cout << BFS() << "\n";

    return 0;
}
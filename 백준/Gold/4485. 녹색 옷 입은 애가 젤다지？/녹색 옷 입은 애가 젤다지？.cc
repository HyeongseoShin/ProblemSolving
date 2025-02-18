// https://www.acmicpc.net/problem/4485

// 다익스트라

#include <bits/stdc++.h>

using namespace std;

int board[200][200];
int dst[200][200];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void BFS(int x, int y, int sz)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    dst[x][y] = board[x][y];

    while(!q.empty())
    {
        auto [curX, curY] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nX = curX + dx[i];
            int nY = curY + dy[i];

            if(nX < 0 || nX >= sz || nY < 0 || nY >= sz) continue;

            // Point: 무조건 재방문이 불가능한 것이 아님!
            // 최소 거리 업데이트 가능하면 방문 후 거리 업데이트
            if(dst[nX][nY] <= dst[curX][curY] + board[nX][nY]) continue;

            dst[nX][nY] = dst[curX][curY] + board[nX][nY];

            q.push({nX, nY});
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int idx = 1;

    while(true)
    {
        int n;

        cin >> n;

        if(n == 0) break;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin >> board[i][j];
                dst[i][j] = INT_MAX;
            }
        }

        BFS(0, 0, n);

        cout << "Problem " << idx << ": " << dst[n-1][n-1] << "\n";
        idx++;

    }

    return 0;
}
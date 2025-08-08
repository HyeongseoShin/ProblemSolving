#include <bits/stdc++.h>

using namespace std;

int n;

int board[501][501];
int dist[501][501];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

int ans = 1;

void BFS()
{
    while(!pq.empty())
    {
        auto [curVal, curX, curY] = pq.top();
        pq.pop();

        for(int i = 0; i < 4; i++)
        {
            int nX = curX + dx[i];
            int nY = curY + dy[i];

            if(nX < 0 || nX >= n || nY < 0 || nY >= n) continue;
            if(board[nX][nY] <= board[curX][curY]) continue;
            if(dist[nX][nY] <= dist[curX][curY] + 1)
            {
                dist[nX][nY] = dist[curX][curY] + 1;
                ans = max(ans, dist[nX][nY]);
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> board[i][j];
            pq.push({board[i][j], i, j});
            dist[i][j] = 1;
        }
    }

    BFS();

    // cout << "\n===============\n";
    // for(int i = 0; i < n; i++)
    // {
    //     for(int j = 0; j < n; j++)
    //     {
    //         cout << dist[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    cout << ans << "\n";


    return 0;
}
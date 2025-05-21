#include <bits/stdc++.h>

using namespace std;

int board[1001][1001];
int n;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int maxCnt = 0;
int minNum = INT_MAX;

void BFS(int x, int y)
{
    queue<pair<int, int>> q;

    q.push({x, y});

    int cnt = 0;

    while(!q.empty())
    {
        auto [curX, curY] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nX = curX + dx[i];
            int nY = curY + dy[i];

            if(board[nX][nY] - board[curX][curY] != 1) continue;
            cnt++;
            q.push({nX, nY});
        }
    }

    if(maxCnt < cnt)
    {
        maxCnt = cnt;
        minNum = board[x][y];
    }

    else if(maxCnt == cnt)
    {
        minNum = min(minNum, board[x][y]);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int testCase;
    cin >> testCase;

    for(int t = 1; t <= testCase; t++)
    {
        cin >> n;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin >> board[i][j];
            }
        }

        maxCnt = 0;
        minNum = INT_MAX;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                BFS(i, j);
            }
        }

        cout << "#" << t << " " << minNum << " " << maxCnt + 1 << "\n";
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int n;
int board[1001][1001];

int ans = 0;
int ansNum = 10000001;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void DFS(int x, int y, int cur, int dist)
{
    for(int i = 0; i < 4; i++)
    {
        int nX = x + dx[i];
        int nY = y + dy[i];

        if(nX < 0 || nX >= n || nY < 0 || nY >= n) continue;
        if(board[x][y] != board[nX][nY] - 1) continue;

        if(ans < dist + 1)
        {
            ans = dist + 1;
            ansNum = cur;
        }

        else if(ans == dist + 1)
        {
            ansNum = min(ansNum, cur);
        }
        
        DFS(nX, nY, cur, dist + 1);
        
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

        ans = 0;
        ansNum = 10000001;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                DFS(i, j, board[i][j], 1);
            }
        }

        cout << "#" << t << " " << ansNum << " " << ans << "\n";

    }
    return 0;
}
// https://www.acmicpc.net/problem/1987
// DFS
#include <bits/stdc++.h>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int r, c;

char board[24][24];

int ans = 1;

bool vis[26]; // 알파벳 방문 확인
void DFS(int x, int y, int curDist)
{
    if(vis[board[x][y] - 'A'])
    {
        ans = max(ans, curDist - 1);
        return;
    }

    vis[board[x][y] - 'A'] = true;

    for(int i = 0; i < 4; i++)
    {
        int nX = x + dx[i];
        int nY = y + dy[i];

        if(nX < 0 || nX >= r || nY < 0 || nY >= c) continue;

        DFS(nX, nY, curDist + 1);
    }

    vis[board[x][y] - 'A'] = false; // 돌아갈 때 다시 방문 초기화
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c;

    for(int i = 0; i < r; i++)
    {
        string s;
        cin >> s;

        for(int j = 0; j < c; j++)
        {
            board[i][j] = s[j];
        }
    }

    DFS(0, 0, 1);

    cout << ans << "\n";

    return 0;
}
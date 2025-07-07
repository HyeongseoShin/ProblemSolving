#include <bits/stdc++.h>

using namespace std;

int n, m;

int board[1001][1001];

// 상, 하, 좌, 우
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// 0: 방문 전, 1: 방문 중, 2: 방문 완료
int vis[1001][1001];

int ans = 0;

void DFS(int x, int y)
{
    vis[x][y] = 1;

    int dir = board[x][y];

    int nX = x + dx[dir];
    int nY = y + dy[dir];

    if(vis[nX][nY] == 0) DFS(nX, nY);

    // 사이클 발생 => 이 구간에 SAFE ZONE 하나 설치해야함
    else if(vis[nX][nY] == 1) ans++;

    // 현재 칸 방문 완료
    vis[x][y] = 2;

    
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
            int dir = 0;
            if(s[j] == 'U') dir = 0;
            else if(s[j] == 'D') dir = 1;
            else if(s[j] == 'L') dir = 2;
            else if(s[j] == 'R') dir = 3;

            board[i][j] = dir;
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(vis[i][j] == 0) DFS(i, j);
        }
    }

    cout << ans << "\n";

    return 0;
}
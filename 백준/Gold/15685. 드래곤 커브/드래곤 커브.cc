#include <bits/stdc++.h>

using namespace std;

int n;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int board[101][101];

void curve(int x, int y, int d, int g)
{
    vector<int> dirs; // 진행 방향 저장
    dirs.push_back(d); // 시작 방향 저장

    int curX = x + dx[d]; // 시작 좌표
    int curY = y + dy[d]; // 시작 좌표

    board[x][y] = 1;
    board[curX][curY] = 1; // 드래곤 커브 표시

    // 세대 별로 드래곤커브 표시 진행
    for(int i = 0; i < g; i++)
    {
        int sz = (int)dirs.size(); // i 세대 방향 수

        // 다음 세대 방향 : 이전 세대 방향 역순, (각 방향 + 1) % 4
        for(int j = sz - 1; j >= 0; j--)
        {
            int nDir = (dirs[j] + 1) % 4; // 다음 세대 방향
            dirs.push_back(nDir); // 다음 세대 방향 추가

            curX += dx[nDir];
            curY += dy[nDir];

            if(curX < 0 || curX > 100 || curY < 0 || curY > 100) continue;

            board[curX][curY] = 1;
        }


    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    while(n--)
    {
        int x, y, d, g;
        cin >> x >> y >> d >> g;

        curve(x, y, d, g);
    }

    int ans = 0;

    for(int i = 0; i < 100; i++)
    {
        for(int j = 0; j < 100; j++)
        {
            if(board[i][j] == 1 && board[i][j+1] == 1 && board[i+1][j] == 1 && board[i+1][j+1] == 1)
            {
                ans++;
            }
        }
    }

    cout << ans << "\n";

    

    return 0;
}
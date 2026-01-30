#include <bits/stdc++.h>

using namespace std;

int board[20][20];

// 현재 위치가 가장 왼쪽 / 위쪽인 상태에서 갈 수 있는 진행방향
int dx[4] = {-1, 0, 1, 1};
int dy[4] = {1, 1, 1, 0};

int ans; // 승자
int ansX = -1, ansY = -1; // 오목의 가장 왼쪽 / 위쪽 돌 위치


// 범위 벗어났는지 확인
bool isOOB(int x, int y)
{
    if(x < 1 || x > 19 || y < 1 || y > 19) return true;
    return false;
}

// 오목 됐는지 확인
bool check(int x, int y)
{
    for(int i = 0; i < 4; i++)
    {
        int cnt = 1;
        int prevX = x - dx[i];
        int prevY = y - dy[i];

        int nX = x + dx[i];
        int nY = y + dy[i];

        if(!isOOB(prevX, prevY) && board[prevX][prevY] == board[x][y]) continue;

        while(!isOOB(nX, nY) && board[x][y] == board[nX][nY])
        {
            cnt++;
            nX += dx[i];
            nY += dy[i];
        }

        if(cnt == 5) return true;
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 1; i <= 19; i++)
    {
        for(int j = 1; j <= 19; j++)
        {
            cin >> board[i][j];
        }
    }

    for(int i = 1; i <= 19; i++)
    {
        bool isFinished = false;
        for(int j = 1; j <= 19; j++)
        {
            isFinished = false;
            if(board[i][j] == 0) continue;

            if(check(i, j))
            {
                isFinished = true;
                ans = board[i][j];
                ansX = i;
                ansY = j;
                break;
            }
        }

        if(isFinished) break;
    }

    cout << ans << "\n";

    
    if(ans != 0) cout << ansX << " " << ansY << "\n";

    return 0;
}
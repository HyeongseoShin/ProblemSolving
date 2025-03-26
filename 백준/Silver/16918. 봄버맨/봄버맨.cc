#include <bits/stdc++.h>

using namespace std;

int r, c, n;

char board[205][205];

int bombTime[205][205];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void SetBomb(int time)
{
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            // 폭탄이 없으면 폭탄 설치
            if(bombTime[i][j] == -1)
            {
                board[i][j] = 'O';
                bombTime[i][j] = time;
            }
        }
    }
}

void Explosion(int time)
{
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(bombTime[i][j] == time - 3)
            {
                for(int dir = 0; dir < 4; dir++)
                {
                    int nX = i + dx[dir];
                    int nY = j + dy[dir];

                    if(nX < 0 || nX >= r || nY < 0 || nY >= c) continue;
                    if(board[nX][nY] == 'O' && bombTime[nX][nY] == bombTime[i][j]) continue;

                    board[nX][nY] = '.';
                    bombTime[nX][nY] = -1;
                }

                bombTime[i][j] = -1;
                board[i][j] = '.';
            }

            
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> r >> c >> n;

    for(int i = 0; i < r; i++)
    {
        string s;
        cin >> s;
        for(int j = 0;j < c; j++)
        {
            bombTime[i][j] = -1;
            board[i][j] = s[j];

            if(board[i][j] == 'O') bombTime[i][j] = 0;
        }
    }

    // 0초 - 초기 폭탄 설치
    // 1초 - 대기

    // 2초부터 시작
    for(int i = 2; i <= n; i++)
    {
        if(i % 2 == 0) SetBomb(i);
        else Explosion(i);
    }

    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            cout << board[i][j];
        }
        cout << "\n";
    }

    return 0;
}
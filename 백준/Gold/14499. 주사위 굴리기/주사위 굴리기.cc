#include <bits/stdc++.h>

using namespace std;

int n, m, k;

int posX, posY;

int board[21][21];

// 동 : 1, 서 : 2, 북 : 3, 남 : 4
int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, 1, -1, 0, 0};

queue<int> op;

// 주사위
// 0 : 윗면, 1 : 북, 2 : 동, 3 : 남, 4 : 서, 5 : 아랫면
int dice[6] = {0, 0, 0, 0, 0, 0};

void moveDice(int dir)
{
    // 동
    if(dir == 1)
    {   
        int d0 = dice[0], d2 = dice[2], d4 = dice[4], d5 = dice[5];

        dice[0] = d2;
        dice[2] = d5;
        dice[4] = d0;
        dice[5] = d4;
    }

    // 서
    else if(dir == 2)
    {
        int d0 = dice[0], d2 = dice[2], d4 = dice[4], d5 = dice[5];

        dice[0] = d4;
        dice[2] = d0;
        dice[4] = d5;
        dice[5] = d2;
    }

    // 북
    else if(dir == 3)
    {   
        int d0 = dice[0], d1 = dice[1], d3 = dice[3], d5 = dice[5];

        dice[0] = d1;
        dice[1] = d5;
        dice[3] = d0;
        dice[5] = d3;
    }

    // 남
    else if(dir == 4)
    {
        int d0 = dice[0], d1 = dice[1], d3 = dice[3], d5 = dice[5];

        dice[0] = d3;
        dice[1] = d0;
        dice[3] = d5;
        dice[5] = d1;
    }
}

void RollDice()
{
    int x = posX;
    int y = posY;

    while(!op.empty())
    {
        int dir = op.front();
        op.pop();

        int nX = x + dx[dir];
        int nY = y + dy[dir];

        if(nX < 0 || nX >= n || nY < 0 || nY >= m) continue;

        moveDice(dir);

        if(board[nX][nY] == 0) board[nX][nY] = dice[5];
        else
        {
            dice[5] = board[nX][nY];
            board[nX][nY] = 0;
        }

        cout << dice[0] << "\n";

        x = nX;
        y = nY;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> posX >> posY >> k;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }

    // 명령 저장
    for(int i = 0; i < k; i++)
    {
        int x;
        cin >> x;

        op.push(x);
    }

    RollDice();

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int board[9][9];

bool isFinished = false;

bool checkIfExsists(int x, int y, int num)
{
    // 가로 확인
    for(int k = 0; k < 9; k++)
    {
        if(board[x][k] == num) return true;
    }

    // 세로 확인
    for(int k = 0; k < 9; k++)
    {
        if(board[k][y] == num) return true;
    }

    // 3x3 확인
    int stX = 0;
    int stY = 0;

    if(x < 3) stX = 0;
    else if(x < 6) stX = 3;
    else if(x < 9) stX = 6;

    if(y < 3) stY = 0;
    else if(y < 6) stY = 3;
    else if(y < 9) stY = 6;

    for(int i = stX; i < stX + 3; i++)
    {
        for(int j = stY; j < stY + 3; j++)
        {
            if(board[i][j] == num) return true;
        }
    }

    return false;
}

void sudoku(int x, int y)
{
    if(isFinished) return;

    // 끝 출력
    if(x > 8)
    {
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }

        isFinished = true;
        return;
    }

    int nX = x;
    int nY = y + 1;

    if(nY == 9)
    {
        nX++;
        nY = 0;
    }

    // 빈 칸 아니면 다음 칸 검사
    if(board[x][y] != 0) sudoku(nX, nY);

    else
    {
        for(int num = 1; num <= 9; num++)
        {
            if(checkIfExsists(x, y, num)) continue;

            // 없으면 삽입 후 백트래킹 진행
            board[x][y] = num;

            sudoku(nX, nY);

            if(isFinished) return;
            board[x][y] = 0;
        }

    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            cin >> board[i][j];
        }
    }

    sudoku(0, 0);



    return 0;
}
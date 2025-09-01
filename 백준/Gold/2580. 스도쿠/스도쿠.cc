#include <bits/stdc++.h>

using namespace std;

int board[9][9];

bool col[10][10]; // col[i][j] : i번째 열에 j가 있는지
bool row[10][10]; // row[i][j] : i번째 해에 j가 있는지
bool box[10][10]; // box[i][j] : i번째 박스에 j가 있는지

int getBoxNum(int x, int y)
{
    return ((x / 3) * 3 + (y / 3));
}


void sudoku(int x, int y)
{
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

        exit(0);
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
            int boxIdx = getBoxNum(x, y);
            if(row[x][num] || col[y][num] || box[boxIdx][num]) continue;

            // 없으면 삽입 후 백트래킹 진행
            row[x][num] = col[y][num] = box[boxIdx][num] = true;
            board[x][y] = num;

            sudoku(nX, nY);

            row[x][num] = col[y][num] = box[boxIdx][num] = false;
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

            // 빈 칸이 아니면 행, 열, 박스에 숫자 있닥 표시하기
            if(board[i][j] != 0)
            {
                int num = board[i][j];
                row[i][num] = true;
                col[j][num]= true;

                int boxIdx = getBoxNum(i, j);

                box[boxIdx][num] = true;
            }
        }
    }

    sudoku(0, 0);

    return 0;
}
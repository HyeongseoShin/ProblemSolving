#include <bits/stdc++.h>

using namespace std;

int board[9][9];

vector<pair<int, int>> pos;

bool isPossible = false;

bool checkRow[9][10]; // checkRow[i][j] : i번째 행에 j가 있으면 true
bool checkCol[9][10]; // checkCol[i][j] : i번째 열에 j가 있으면 true
bool checkBox[9][10]; // checkCol[i][j] : i번째 3x3구간에 j가 있으면 true

void Solve(int cnt)
{
    if(isPossible) return;

    if(cnt == (int)pos.size())
    {
        isPossible = true;
        return;
    }

    // int tmp[9][9];

    auto [curX, curY] = pos[cnt];

    for(int num = 1; num <= 9; num++)
    {
        // 원본 복사
        // for(int i = 0; i < 9; i++)
        // {
        //     for(int j = 0; j < 9; j++)
        //     {
        //         tmp[i][j] = board[i][j];
        //     }
        // }

        if(!checkRow[curX][num] && !checkCol[curY][num] && !checkBox[(curX / 3) * 3 + (curY / 3)][num])
        {
            board[curX][curY] = num;
            checkRow[curX][num] = true;
            checkCol[curY][num] = true;
            checkBox[(curX / 3) * 3 + (curY / 3)][num] = true;

            Solve(cnt + 1);

            if(isPossible) return;

            board[curX][curY] = 0;
            checkRow[curX][num] = false;
            checkCol[curY][num] = false;
            checkBox[(curX / 3) * 3 + (curY / 3)][num] = false;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 9; i++)
    {
        string s;
        cin >> s;

        for(int j = 0; j < 9; j++)
        {
            board[i][j] = s[j] - '0';
            checkRow[i][board[i][j]] = true;
            checkCol[j][board[i][j]] = true;
            checkBox[(i/3) * 3 + (j/3)][board[i][j]] = true;

            if(board[i][j] == 0) pos.push_back({i, j});
        }
    }

    Solve(0);

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            cout << board[i][j];
        }
        cout << "\n";
    }


    return 0;
}
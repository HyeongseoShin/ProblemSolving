#include <bits/stdc++.h>

using namespace std;

int board[9][9];

vector<pair<int, int>> pos;

bool isPossible = false;
bool CheckHorizontal(int x, int y)
{
    for(int i = 0; i < 9; i++)
    {
        if(i == y) continue;
        if(board[x][i] == board[x][y]) return false;
    }

    return true;
}

bool CheckVertical(int x, int y)
{
    for(int i = 0; i < 9; i++)
    {
        if(i == x) continue;
        if(board[i][y] == board[x][y]) return false;
    }
    
    return true;
}

bool Check3x3(int x, int y)
{
    int stX, stY;
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
            if(i == x && j == y) continue;

            if(board[i][j] == board[x][y]) return false;
        }
    }

    return true;
}

void Solve(int cnt)
{
    if(isPossible) return;

    if(cnt == (int)pos.size())
    {
        isPossible = true;
        return;
    }

    int tmp[9][9];

    auto [curX, curY] = pos[cnt];

    for(int num = 1; num <= 9; num++)
    {
        // 원본 복사
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                tmp[i][j] = board[i][j];
            }
        }

        board[curX][curY] = num;
        if(CheckHorizontal(curX, curY) && CheckVertical(curX, curY) && Check3x3(curX, curY))
        {
            Solve(cnt + 1);
        }
        else board[curX][curY] = 0;

        if(isPossible) return;

        // 복구
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                board[i][j] = tmp[i][j];
            }
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
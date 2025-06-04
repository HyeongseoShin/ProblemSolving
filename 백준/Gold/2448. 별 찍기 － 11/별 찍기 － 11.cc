#include <bits/stdc++.h>

using namespace std;

char board[4000][8000];

int n;

void DrawStar(int x, int y)
{
    board[x][y] = '*';
    board[x+1][y-1] = '*';
    board[x+1][y+1] = '*';

    for(int j = y - 2; j <= y + 2; j++)
    {
        board[x+2][j] = '*';
    }
}

void Recursive(int len, int x, int y)
{
    if(len == 3)
    {
        DrawStar(x, y);
        return;
    }

    Recursive(len / 2, x, y);
    Recursive(len / 2, x + len / 2, y - len / 2);
    Recursive(len / 2, x + len / 2, y + len / 2);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    Recursive(n, 1, n);

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n * 2; j++)
        {
            if(!board[i][j]) board[i][j] = ' ';
            cout << board[i][j];
        }
        cout << "\n";
    }


    return 0;
}
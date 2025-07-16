#include <bits/stdc++.h>

using namespace std;

int n;

char board[5000][5000];

// (시작X, 시작Y, 한 변의 길이)
void draw(int x, int y, int sz)
{
    if(sz == 1)
    {
        board[x][y] = '*';
        return;
    }

    int div = sz / 3;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            // 가운데 공백
            if(i == 1 && j == 1) continue;

            draw(x + i * div, y + j * div, div);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    // 공백으로 초기화
    for(int i = 0; i < n; i++)
    {
        fill(board[i], board[i] + n, ' ');
    }

    draw(0, 0, n);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << board[i][j];
        }
        cout << "\n";
    }

    return 0;
}
// https://www.acmicpc.net/problem/14719
#include <bits/stdc++.h>

using namespace std;

int board[512][512];

int w, h;

int ans = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> w >> h;

    for(int i = 0; i < h; i++)
    {
        int x;

        cin >> x;

        for(int j = 0; j < x; j++)
        {
            board[w - 1 - j][i] = 1;
        }   
    }

    for(int i = 0; i < w; i++)
    {
        int cur = 0;
        int st = 0;
        for(int j = 0; j < h; j++)
        {
            if(board[i][j] == 0 && board[i][st] != 0) cur++;
            else if(board[i][j] == 1)
            {
                if(cur != 0)
                {
                    ans += cur;
                    cur = 0;
                }
                st = j;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
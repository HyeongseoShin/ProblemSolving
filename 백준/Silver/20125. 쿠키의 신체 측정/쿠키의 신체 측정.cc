// https://www.acmicpc.net/problem/20125
#include <bits/stdc++.h>

using namespace std;

int n;

char board [2002][2002];

int x[4] = {-1, 1, 0, 0};
int y[4] = {0, 0, -1, 1};

int hX = -1, hY = -1;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        string s;

        cin >> s;

        for(int j = 0; j < n; j++)
        {
            board[i][j] = s[j];
        }
    }

    // cout << "\n\n\n";
    // for(int i = 0 ;i < n; i++)
    // {
    //     for(int j = 0; j < n; j++)
    //     {
    //         cout << board[i][j];
    //     }
    //     cout << "\n";
        
    // }
    

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(board[i][j] == '*')
            {
                bool isPossible = true;
                for(int k = 0; k < 4; k++)
                {
                    int nX = i + x[k];
                    int nY = j + y[k];

                    if(nX < 0 || nX > n || nY < 0 || nY > n || board[nX][nY] == '_')
                    {
                        isPossible = false;
                        break;
                    }
                }

                if(isPossible)
                {
                    hX = i;
                    hY = j;
                    break;
                }
            }  
        }

        if(hX != -1 && hY != -1) break;
    }

    cout << hX + 1 << " " << hY + 1 << "\n";

    // 왼쪽 팔
    int curY = hY - 1;
    int cnt = 0;
    while(curY >= 0 && board[hX][curY] == '*')
    {
        curY--;
        cnt++;
    }
    cout << cnt << " ";

    // 오른쪽 팔
    curY = hY + 1;
    cnt = 0;
    while(curY < n && board[hX][curY] == '*')
    {
        curY++;
        cnt++;
    }
    cout << cnt << " ";

    // 허리
    int curX = hX + 1;
    cnt = 0;
    while(curX < n && board[curX][hY] == '*')
    {
        curX++;
        cnt++;
    }
    cout << cnt << " ";

    int lX = curX;
    int lY = hY - 1;

    int rX = curX;
    int rY = hY + 1;

    // 왼쪽 다리
    curX = lX;
    cnt = 0;
    while(curX < n && board[curX][lY] == '*')
    {
        curX++;
        cnt++;
    }
    cout << cnt << " ";

    // 오른쪽 다리
    curX = rX;
    cnt = 0;
    while(curX < n && board[curX][rY] == '*')
    {
        curX++;
        cnt++;
    }
    cout << cnt << "\n";

    return 0;
}
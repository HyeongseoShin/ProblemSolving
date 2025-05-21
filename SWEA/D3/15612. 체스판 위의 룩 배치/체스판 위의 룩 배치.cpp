#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int testCase;
    cin >> testCase;

    for(int t = 1; t <= testCase; t++)
    {
        char board[8][8];

        int cnt = 0;
        for(int i = 0; i < 8; i++)
        {
            string s;
            cin >> s;

            
            for(int j = 0; j < 8; j++)
            {
                board[i][j] = s[j];

                if(board[i][j] == 'O') cnt++;
            }
        }

        cout << "#" << t << " ";
        if(cnt != 8)
        {
            cout << "no\n";
            continue;
        }

        bool row[8];
        bool col[8];

        fill(row, row + 8, false);
        fill(col, col + 8, false);

        bool isPossible = true;
        for(int i = 0; i < 8; i++)
        {
            for(int j = 0; j < 8; j++)
            {
                if(board[i][j] == 'O')
                {
                    if(row[i] || col[j])
                    {
                        isPossible = false;
                        break;
                    }

                    row[i] = true;
                    col[j] = true;
                }
            }

            if(!isPossible) break;
        }

        if(isPossible) cout << "yes\n";
        else cout << "no\n";


    }
    return 0;
}
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
        char board[5][15];

        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 15; j++)
            {
                board[i][j] = '!';
            }
        }

        for(int i = 0; i < 5; i++)
        {
            string s;
            cin >> s;
            
            for(int j = 0; j < (int)s.length(); j++)
            {
                board[i][j] = s[j];
            }
        }

        string ans = "";
        for(int i = 0; i < 15; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                if(board[j][i] == '!') continue;
                ans += board[j][i];
            }
        }

        cout << "#" << t << " " << ans << "\n";
    }

    return 0;
}
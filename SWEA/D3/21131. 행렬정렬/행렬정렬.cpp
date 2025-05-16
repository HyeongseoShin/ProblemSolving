#include <bits/stdc++.h>

using namespace std;

int n;

int board[65][65];

bool isSame[65];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int testCase;
    cin >> testCase;

    for(int t = 1; t <= testCase; t++)
    {
        cin >> n;

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                cin >> board[i][j];
            }
        }

        fill(isSame, isSame + n + 1, true);

        for(int i = 2; i <= n; i++)
        {
            if(board[i][i-1] != (i - 1) * n + (i - 1)) isSame[i] = false;
        }

        int ans = 0;
        for(int i = n; i >= 2; i--)
        {
            if(isSame[i]) continue;
            ans++;
            for(int j = i; j >= 2; j--)
            {
                isSame[j] = !isSame[j];
            }
        }

        cout << ans << "\n";

    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int board[100][100];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int t = 1; t <= 10; t++)
    {
        int n;
        cin >> n;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin >> board[i][j];
            }
        }

        int ans = 0;

        // 한 열에서 위에서 아래로 순회하며 N극이 있으면 표시 후 S극을 만나면 ans++
        for(int i = 0; i < n; i++)
        {
            int prev = 0;
            for(int j = 0; j < n; j++)
            {
                if(board[j][i] == 1) prev = 1;
                else if(board[j][i] == 2 && prev == 1)
                {
                    prev = 2;
                    ans++;
                }
            }
        }

        cout << "#" << t << " " << ans << "\n";
    }


    return 0;
}
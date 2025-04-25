#include <bits/stdc++.h>

using namespace std;

int m, n;

int bug[701][701];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;
    memset(bug, 1, sizeof(bug));

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < m; j++)
        {
            bug[i][j] = 1;
        }
    }

    while(n--)
    {
        int cnt[3];

        for(int i = 0; i < 3; i++)
        {
            cin >> cnt[i];
        }

        int idx = 0;

        int x = m - 1;
        int y = 0;

        while(true)
        {
            while(cnt[idx] == 0) idx++;
            
            // cout << "Before x: " << x << " y: " << y << " idx: " << idx << " cnt[idx] : " << cnt[idx] << "\n";
            bug[x][y] += idx;
            cnt[idx]--;

            if(x > 0) x--;

            else if(x == 0) y++;

            // cout << "After x: " << x << " y: " << y << " idx: " << idx << " cnt[idx] : " << cnt[idx] << "\n";

            if(x == 0 && y == m) break;
        }

        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < m; j++)
            {
                bug[i][j] = max(bug[i-1][j-1], max(bug[i-1][j], bug[i][j-1]));
            }
        }
    }

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << bug[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
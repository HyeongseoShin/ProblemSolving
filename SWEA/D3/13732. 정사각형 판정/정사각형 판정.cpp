#include <bits/stdc++.h>

using namespace std;

int n;

char board[20][20];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int testCase;
    cin >> testCase;

    for(int t = 1; t <= testCase; t++)
    {
        cin >> n;

        int minX = 21, minY = 21;
        int maxX = 0, maxY = 0;


        bool isPossible = false;
        for(int i = 0; i < n; i++)
        {
            string s;
            cin >> s;

            for(int j = 0; j < n; j++)
            {
                board[i][j] = s[j];

                if(board[i][j] == '#')
                {
                    isPossible = true;
                    minX = min(minX, i);
                    minY = min(minY, j);

                    maxX = max(maxX, i);
                    maxY = max(maxY, j);
                }
            }
        }

        if(maxX - minX != maxY - minY) isPossible = false;
        
        if(!isPossible)
        {
            cout << "#" << t << " no\n";
            continue;
        }

        for(int i = minX; i <= maxX; i++)
        {
            for(int j = minY; j <= maxY; j++)
            {
                if(board[i][j] != '#')
                {
                    isPossible = false;
                    break;
                }
            }

            if(!isPossible) break;
        }

        cout << "#" << t << " ";
        if(isPossible) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}
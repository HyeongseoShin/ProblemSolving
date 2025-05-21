#include <bits/stdc++.h>

using namespace std;

#define MAX 301

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int testCase;
    cin >> testCase;

    int board[MAX][MAX];

    pair<int, int> pos[10005];

    for(int i = 1; i < MAX; i++)
    {
        if(i == 1)
        {
            board[i][1] = 1;
            pos[1] = {1, 1};
        }
        else
        {
            board[i][1] = board[i-1][1] + (i - 1);
            int num = board[i-1][1] + (i - 1);

            if(num <= 10000) pos[num] = {i, 1};
        }
        
        int cnt = i + 1;
        for(int j = 2; j < MAX; j++)
        {
            int idx = board[i][j-1] + cnt;
            board[i][j] = idx;

            if(idx <= 10000) pos[idx] = {i, j};
            cnt++;
        }
    }


    for(int t = 1; t <= testCase; t++)
    {
        int p, q;
        cin >> p >> q;

        pair<int, int> andP = pos[p];
        pair<int, int> andQ = pos[q];

        pair<int, int> result = {andP.first + andQ.first, andP.second + andQ.second};

        cout << "#" << t << " " << board[result.first][result.second] << "\n";
    }

    return 0;
}
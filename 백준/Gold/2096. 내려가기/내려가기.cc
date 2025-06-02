#include <bits/stdc++.h>

using namespace std;

int n;

int maxDp[3]; // 현재 행, 칸에서 만들 수 있는 최대값

int minDp[3]; // 현재 행, 칸에서 만들 수 있는 최소값

int board[3];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    cin >> maxDp[0] >> maxDp[1] >> maxDp[2];

    minDp[0] = maxDp[0];
    minDp[1] = maxDp[1];
    minDp[2] = maxDp[2];

    for(int i = 1; i < n; i++)
    {
        cin >> board[0] >> board[1] >> board[2];

        int temp0, temp2;
        temp0 = maxDp[0];
        temp2 = maxDp[2];

        maxDp[0] = max(maxDp[0], maxDp[1]) + board[0];
        maxDp[2] = max(maxDp[2], maxDp[1]) + board[2];
        maxDp[1] = max({temp0, maxDp[1], temp2}) + board[1];

        temp0 = minDp[0];
        temp2 = minDp[2];

        minDp[0] = min(minDp[0], minDp[1]) + board[0];
        minDp[2] = min(minDp[2], minDp[1]) + board[2];
        minDp[1] = min({temp0, minDp[1], temp2}) + board[1];
    }

    int minAns = min({minDp[0], minDp[1], minDp[2]});
    int maxAns = max({maxDp[0], maxDp[1], maxDp[2]});

    cout << maxAns << " " << minAns << "\n";
    
    return 0;
}
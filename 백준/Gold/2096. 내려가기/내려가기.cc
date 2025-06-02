#include <bits/stdc++.h>

using namespace std;

int n;

int maxDp[3]; // 현재 행, 칸에서 만들 수 있는 최대값

int minDp[3]; // 현재 행, 칸에서 만들 수 있는 최소값

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int board[3];
        cin >> board[0] >> board[1] >> board[2];

        if(i == 0)
        {
           for(int j = 0; j < 3; j++)
           {
                maxDp[j] = board[j];
                minDp[j] = board[j];
           }
        }

        else
        {
            int maxTmp[3];
            fill(maxTmp, maxTmp + 3, 0);

            int minTmp[3];
            fill(minTmp, minTmp + 3, 0);

            for(int j = 0; j < 3; j++)
            {
                int minVal = INT_MAX;
                int maxVal = 0;

                if(j <= 1)
                {
                    minVal = min(minVal, board[j] + minDp[0]);
                    maxVal = max(maxVal, board[j] + maxDp[0]);
                }

                minVal = min(minVal, board[j] + minDp[1]);
                maxVal = max(maxVal, board[j] + maxDp[1]);

                if(j >= 1)
                {
                    minVal = min(minVal, board[j] + minDp[2]);
                    maxVal = max(maxVal, board[j] + maxDp[2]);
                }

                minTmp[j] = minVal;
                maxTmp[j] = maxVal;
            }

            for(int j = 0; j < 3; j++)
            {
                minDp[j] = minTmp[j];
                maxDp[j] = maxTmp[j];
            }
        }
    }

    int minAns = INT_MAX;
    int maxAns = 0;

    for(int j = 0; j < 3; j++)
    {
        minAns = min(minAns, minDp[j]);
        maxAns = max(maxAns, maxDp[j]);
    }

    cout << maxAns << " " << minAns << "\n";
    
    return 0;
}
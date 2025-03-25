#include <bits/stdc++.h>

using namespace std;

int n, k;

struct Player
{
    int x, y, dir;
};

// 0 : 흰색, 1: 빨간색, 2: 파란색
int chess[15][15];

// 현재 체스판에서 쌓여있는 말 상태
vector<int> curStatus[15][15];

// (x, y, 방향)
Player player[15];

// 우, 좌, 상, 하
int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, 1, -1, 0, 0};

int maxStackCnt = 0;

void Move(int x, int y, int dir)
{
    int nX = x + dx[dir];
    int nY = y + dy[dir];

    // 파란색
    if(nX < 1 || nX > n || nY < 1 || nY > n || chess[nX][nY] == 2)
    {
        if(dir % 2 == 1) dir++;
        else dir--;

        nX = x + dx[dir];
        nY = y + dy[dir]; // 무한루프 원인 : dx[dir] 더했었음

        player[curStatus[x][y][0]].dir = dir;

        // if(nX < 1 || nX > n || nY < 1 || nY > n || chess[nX][nY] == 2)
        // {
        // }

        // else
        // {
        //     // 흰색
        //     if(chess[nX][nY] == 0)
        //     {
        //         for(int i = 0; i < (int)curStatus[x][y].size(); i++)
        //         {
        //             curStatus[nX][nY].push_back(curStatus[x][y][i]);
        //             player[curStatus[x][y][i]].x = nX;
        //             player[curStatus[x][y][i]].y = nY;
        //         }

        //         curStatus[x][y].clear();
        //     }

        //     // 빨간색
        //     else if(chess[nX][nY] == 1)
        //     {
        //         reverse(curStatus[x][y].begin(), curStatus[x][y].end());

        //         for(int i = 0; i < (int)curStatus[x][y].size(); i++)
        //         {
        //             curStatus[nX][nY].push_back(curStatus[x][y][i]);
        //             player[curStatus[x][y][i]].x = nX;
        //             player[curStatus[x][y][i]].y = nY;
        //         }

        //         curStatus[x][y].clear();
        //     }
        // }
    }

    if(nX >= 1 && nX <= n && nY >= 1 && nY <= n)
    {
        // 흰색
        if(chess[nX][nY] == 0)
        {
            for(int i = 0; i < (int)curStatus[x][y].size(); i++)
            {
                curStatus[nX][nY].push_back(curStatus[x][y][i]);
                player[curStatus[x][y][i]].x = nX;
                player[curStatus[x][y][i]].y = nY;
            }

            curStatus[x][y].clear();
        }

        // 빨간색
        else if(chess[nX][nY] == 1)
        {
            reverse(curStatus[x][y].begin(), curStatus[x][y].end());

            for(int i = 0; i < (int)curStatus[x][y].size(); i++)
            {
                curStatus[nX][nY].push_back(curStatus[x][y][i]);
                player[curStatus[x][y][i]].x = nX;
                player[curStatus[x][y][i]].y = nY;
            }

            curStatus[x][y].clear();
        }

        // 쌓인 말 최대 개수 확인
        maxStackCnt = max(maxStackCnt, (int)curStatus[nX][nY].size());
    }
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> chess[i][j];
        }   
    }

    for(int i = 1; i <= k; i++)
    {
        int x, y, dir;

        cin >> x >> y >> dir;

        curStatus[x][y].push_back(i);

        player[i] = {x, y, dir};
    }

    int ans = 1;
    while(ans <= 1000)
    {
        for(int i = 1; i <= k; i++)
        {
            auto [x, y, dir] = player[i];

            // 가장 아래에 있는 게 아니면 스킵
            if(curStatus[x][y][0] != i) continue;

            Move(x, y, dir);

            if(maxStackCnt >= 4) break;
        }

        if(maxStackCnt >= 4) break;

        ans++;
    }

    if(ans > 1000) ans = -1;
    
    cout << ans << "\n";

    return 0;
}
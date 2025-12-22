#include <bits/stdc++.h>

using namespace std;

int n, m;

int board[7][7];

bool isUsed[7][7];

int ans = 0;

// 범위 밖인지 확인
bool isPossible(int x, int y)
{
    if(x < 0 || x >= n || y < 0 || y >= m) return false;
    if(isUsed[x][y]) return false;

    return true;
}

// 상, 하, 좌, 우
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// ㄱ자 만들 수 있는 좌표 위치
int dir[4][2] = {
    {0, 2},
    {0, 3},
    {1, 2},
    {1, 3}
};

void dfs(int x, int y, int sum)
{
    bool tmpIsUsed[7][7];
    memcpy(tmpIsUsed, isUsed, sizeof(tmpIsUsed));

    if(x >= n)
    {
        ans = max(ans, sum);
        return;
    }

    // 아직 사용안됐으면
    if(!isUsed[x][y])
    {
        for(int i = 0; i < 4; i++)
        {
            int tmp = 0;
            bool can = true;
            isUsed[x][y] = true;

            for(int j = 0; j < 2; j++)
            {
                int curDir = dir[i][j];
                int nX = x + dx[curDir];
                int nY = y + dy[curDir];

                if(!isPossible(nX, nY))
                {
                    can = false;
                    break;
                }

                isUsed[nX][nY] = true;
                tmp += board[nX][nY];
            }

            int tmpX = x;
            int tmpY = y;
            tmpY++;

            if(tmpY >= m)
            {
                tmpX++;
                tmpY = 0;
            }

            if(can)
            {
                // cout << "x: " << x << " y: " << y << " 계산값: " << board[x][y] * 2 + tmp << "\n";
                dfs(tmpX, tmpY, sum + board[x][y] * 2 + tmp);
            }

            memcpy(isUsed, tmpIsUsed, sizeof(isUsed));
        }
    }

    int nX = x;
    int nY = y;

    nY++;

    if(nY >= m)
    {
        nX++;
        nY = 0;
    }

    dfs(nX, nY, sum);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }

    dfs(0, 0, 0);

    cout << ans << "\n";

    return 0;
}
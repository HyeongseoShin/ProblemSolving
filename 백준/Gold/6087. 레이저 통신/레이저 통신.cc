#include <bits/stdc++.h>

using namespace std;

int w, h;

char board[105][105];

int mirror[105][105][4];

vector<pair<int,int>> cPos;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void BFS(int x, int y)
{
    // 현재 좌표 x, y , 들어온 방향
    queue<tuple<int, int, int>> q;

    // 시작점에서 4방향 미리 q 삽입
    for(int i = 0; i < 4; i++)
    {
        mirror[x][y][i] = 0;
        q.push({x, y, i});
    }

    while(!q.empty())
    {
        auto [curX, curY, curDir] = q.front();
        
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nX = curX + dx[i];
            int nY = curY + dy[i];

            if(nX < 0 || nX >= h || nY < 0 || nY >= w) continue;
            if(board[nX][nY] == '*') continue;

            if(i != curDir)
            {
                if(mirror[nX][nY][i] > mirror[curX][curY][curDir] + 1)
                {
                    mirror[nX][nY][i] = mirror[curX][curY][curDir] + 1;
                    q.push({nX, nY, i});
                }
            }

            else
            {
                if(mirror[nX][nY][i] > mirror[curX][curY][curDir])
                {
                    mirror[nX][nY][i] = mirror[curX][curY][curDir];
                    q.push({nX, nY, i});
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> w >> h;

    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            cin >> board[i][j];

            if(board[i][j] == 'C')
            {
                cPos.push_back({i, j});
            }
        }
    }

    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            for(int k = 0; k < 4; k++)
            {
                mirror[i][j][k] = 100005;
            }
            
        }
    }

    auto [x, y] = cPos[0];
    BFS(x, y);

    // for(int i = 0; i < h; i++)
    // {
    //     for(int j = 0; j < w; j++)
    //     {
    //         cout.width(10);
    //         cout << mirror[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    auto [ansX, ansY] = cPos[1];
    
    int ans = INT_MAX;
    for(int i = 0; i < 4; i++)
    {
        ans = min(ans, mirror[ansX][ansY][i]);
    }

    cout << ans << "\n";


    return 0;
}
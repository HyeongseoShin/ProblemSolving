#include <bits/stdc++.h>

using namespace std;

int board[20][20];

int n;

int sharkX, sharkY;

int sharkSize = 2;
int eatCnt = 0;

bool isPossible = true;

int ans = 0;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void BFS()
{
    queue<tuple<int, int>> q;
    q.push({sharkX, sharkY});

    int dist[20][20];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            dist[i][j] = INT_MAX;
        }
    }

    dist[sharkX][sharkY] = 0;

    int cnt = INT_MAX;
    int fishPosX = n;
    int fishPosY = n;

    while(!q.empty())
    {
        auto [curX, curY] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nX = curX + dx[i];
            int nY = curY + dy[i];

            if(nX < 0 || nX >= n || nY < 0 || nY >= n) continue;
            if(board[nX][nY] > sharkSize) continue;
            if(dist[nX][nY] != INT_MAX) continue;

            dist[nX][nY] = dist[curX][curY] + 1;
            q.push({nX, nY});

            // 다음 칸에 먹을 수 있는 물고기가 있다면
            if(board[nX][nY] >= 1 && board[nX][nY] <= 6 && board[nX][nY] < sharkSize)
            {
                // 만약 현재까지의 거리가 현재 타겟 물고기까지의 거리보다 가까우면 업데이트
                if(cnt > dist[nX][nY])
                {
                    cnt = dist[nX][nY];
                    fishPosX = nX;
                    fishPosY = nY;
                }

                else if(cnt == dist[nX][nY])
                {
                    if(fishPosX > nX || (fishPosX == nX && fishPosY > nY))
                    {
                        fishPosX = nX;
                        fishPosY = nY;
                    }
                }
            }
        }
    }

    // 먹을 수 있는 물고기가 없다면
    if(cnt == INT_MAX)
    {
        isPossible = false;
    }

    else
    {
        eatCnt++;
        board[sharkX][sharkY] = 0;

        if(eatCnt == sharkSize)
        {
            eatCnt = 0;
            sharkSize++;
        }

        sharkX = fishPosX;
        sharkY = fishPosY;

        board[sharkX][sharkY] = 9;
        ans += cnt;
    }
    
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> board[i][j];

            if(board[i][j] == 9)
            {
                sharkX = i;
                sharkY = j;
            }
        }
    }

    while(isPossible)
    {
        BFS();
    }

    cout << ans << "\n";

    return 0;
}
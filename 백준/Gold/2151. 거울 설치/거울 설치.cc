#include <bits/stdc++.h>

using namespace std;

int n;

// # : 문
// . : 빈 칸
// ! : 거울 설치 위치 후보
char board[51][51];

// 상, 좌, 하, 우
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int stX = -1, stY = -1, enX = -1, enY = -1;

int cnt[51][51][4]; // (x, y) 까지 dir 방향으로 오는 데에 설치한 최소 거울 개수

void Dijkstra(int x, int y)
{
    // 거울 개수, x, y, 진행 방향
    priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<>> pq;

    for(int i = 0; i < 4; i++)
    {
        cnt[x][y][i] = 0;
        pq.push({cnt[x][y][i], x, y, i});
    }

    while(!pq.empty())
    {
        auto [curCnt, curX, curY, curDir] = pq.top();
        pq.pop();

        int nX = curX + dx[curDir];
        int nY = curY + dy[curDir];

        if(nX < 0 || nX >= n || nY < 0 || nY >= n) continue; // 범위 넘으면 패스
        if(board[nX][nY] == '*') continue; // 벽이면 패스

        // 같은 방향 진행
        if(cnt[nX][nY][curDir] > curCnt)
        {
            cnt[nX][nY][curDir] = curCnt;
            pq.push({cnt[nX][nY][curDir], nX, nY, curDir});
        }

        // 거울 위치 후보면 거울 설치
        if(board[nX][nY] == '!')
        {
            
            int prevDir = (curDir - 1) % 4;
            if(prevDir < 0) prevDir += 4;

            if(cnt[nX][nY][prevDir] > curCnt + 1)
            {
                cnt[nX][nY][prevDir] = curCnt + 1;
                pq.push({cnt[nX][nY][prevDir], nX, nY, prevDir});
            }

            int nxtDir = (curDir + 1) % 4;

            if(cnt[nX][nY][nxtDir] > curCnt + 1)
            {
                cnt[nX][nY][nxtDir] = curCnt + 1;
                pq.push({cnt[nX][nY][nxtDir], nX, nY, nxtDir});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        for(int j = 0; j < n; j++)
        {
            board[i][j] = s[j];

            if(board[i][j] == '#')
            {
                if(stX == -1)
                {
                    stX = i;
                    stY = j;
                }
                else
                {
                    enX = i;
                    enY = j;
                }
                
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int dir = 0; dir < 4; dir++)
            {
                cnt[i][j][dir] = INT_MAX;
            }
        }
    }

    Dijkstra(stX, stY);

    int ans = INT_MAX;
    for(int i = 0; i < 4; i++)
    {
        ans = min(ans, cnt[enX][enY][i]);
    }
    
    cout << ans << "\n";

    return 0;
}
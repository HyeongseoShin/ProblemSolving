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

int cnt[51][51]; // (x, y) 까지 오는 데에 설치한 최소 거울 개수


void Dijkstra(int x, int y)
{
    // 거울 개수, x, y, 진행 방향
    priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<>> pq;
    cnt[x][y] = 0;

    pq.push({cnt[x][y], x, y, 0});
    pq.push({cnt[x][y], x, y, 1});
    pq.push({cnt[x][y], x, y, 2});
    pq.push({cnt[x][y], x, y, 3});

    while(!pq.empty())
    {
        auto [curCnt, curX, curY, curDir] = pq.top();
        pq.pop();

        int nX = curX + dx[curDir];
        int nY = curY + dy[curDir];

        if(nX < 0 || nX >= n || nY < 0 || nY >= n) continue;

        // 빈 칸이면 계속 전진
        while(board[nX][nY] == '.')
        {
            nX += dx[curDir];
            nY += dy[curDir];
        }

        // 도착 지점이 거울 설치 위치 후보나 문이 아니면 패스
        if(board[nX][nY] != '!' && board[nX][nY] != '#') continue;

        if(cnt[nX][nY] <= curCnt) continue;

        cnt[nX][nY] = curCnt;

        // 거울 위치 후보면
        if(board[nX][nY] == '!')
        {
            // 거울 설치 X
            pq.push({curCnt, nX, nY, curDir});

            cnt[nX][nY] = curCnt + 1;
            // 거울 설치
            int prevDir = (curDir - 1) % 4;
            if(prevDir < 0) prevDir += 4;
            int nxtDir = (curDir + 1) % 4;
            pq.push({curCnt + 1, nX, nY, prevDir});
            pq.push({curCnt + 1, nX, nY, nxtDir});
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
            cnt[i][j] = INT_MAX;
        }
    }
    Dijkstra(stX, stY);

    cout << cnt[enX][enY] << "\n";

    return 0;
}
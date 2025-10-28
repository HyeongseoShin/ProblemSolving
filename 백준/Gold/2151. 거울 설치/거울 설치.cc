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

// 0-1 BFS
void BFS(int x, int y)
{
    // <x, y, 방향>
    deque<tuple<int, int, int>> dq;

    for(int i = 0; i < 4; i++)
    {
        cnt[x][y][i] = 0;
        dq.push_front({x, y, i});
    }

    while(!dq.empty())
    {
        auto [curX, curY, curDir] = dq.front();
        dq.pop_front();

        int nX = curX + dx[curDir];
        int nY = curY + dy[curDir];

        if(nX < 0 || nX >= n || nY < 0 || nY >= n) continue;
        if(board[nX][nY] == '*') continue;

        
        // 거울 설치 안하는 방법을 먼저 방문
        if(cnt[nX][nY][curDir] > cnt[curX][curY][curDir])
        {
            cnt[nX][nY][curDir] = cnt[curX][curY][curDir];
            dq.push_front({nX, nY, curDir});
        }

        if(board[nX][nY] == '!')
        {
            int prevDir = (curDir - 1) % 4;
            if(prevDir < 0) prevDir += 4;

            if(cnt[nX][nY][prevDir] > cnt[curX][curY][curDir] + 1)
            {
                cnt[nX][nY][prevDir] = cnt[curX][curY][curDir] + 1;
                dq.push_back({nX, nY, prevDir});
            }

            int nDir = (curDir + 1) % 4;

            if(cnt[nX][nY][nDir] > cnt[curX][curY][curDir] + 1)
            {
                cnt[nX][nY][nDir] = cnt[curX][curY][curDir] + 1;
                dq.push_back({nX, nY, nDir});
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

    // 0-1 BFS
    BFS(stX, stY);

    int ans = INT_MAX;
    for(int i = 0; i < 4; i++)
    {
        ans = min(ans, cnt[enX][enY][i]);
    }
    
    cout << ans << "\n";

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int n, m;

char board[10][10];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// <rX, rY, bX, bY>일 때 방문 여부
bool vis[10][10][10][10];

// <현재 rX, rY, 현재 bX, bY, 이동 횟수>
struct State
{
    int rX, rY, bX, bY, cnt;
};

// 구슬 이동
pair<int, int> move(int x, int y, int dir, int& cnt)
{
    cnt = 0;

    // 벽에 닿을 때까지 이동
    while(true)
    {
        if(board[x + dx[dir]][y + dy[dir]] == '#') break;
        x += dx[dir];
        y += dy[dir];
        cnt++;

        // 도착점 닿으면 끝
        if(board[x][y] == 'O') break;
    }

    return {x, y};
}

int BFS(int rX, int rY, int bX, int bY)
{
    queue<State> q;
    vis[rX][rY][bX][bY] = true;
    q.push({rX, rY, bX, bY, 0});

    while(!q.empty())
    {
        auto [curRx, curRy, curBx, curBy, curCnt] = q.front();
        q.pop();

        // 이동 횟수 10번 넘으면 끝
        if(curCnt >= 10) break;
        

        for(int i = 0; i < 4; i++)
        {
            // 각 구슬이 이동한 횟수
            int rCnt = 0, bCnt = 0;

            auto [nRx, nRy] = move(curRx, curRy, i, rCnt);
            auto [nBx, nBy] = move(curBx, curBy, i, bCnt);

            // 파란 구슬 빠지면 실패
            if(board[nBx][nBy] == 'O') continue;

            // 빨간 구슬만 들어가면 성공
            if(board[nRx][nRy] == 'O') return curCnt + 1;

            // 두 구슬이 겹치면, 더 많이 이동한 구슬을 한 칸 뒤로
            if(nRx == nBx && nRy == nBy)
            {
                if(rCnt > bCnt)
                {
                    nRx -= dx[i];
                    nRy -= dy[i];
                }
                else
                {
                    nBx -= dx[i];
                    nBy -= dy[i];
                }
            }

            // 방문 표시
            if(!vis[nRx][nRy][nBx][nBy])
            {
                vis[nRx][nRy][nBx][nBy] = true;
                q.push({nRx, nRy, nBx, nBy, curCnt + 1});
            }
        }


    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int rX, rY, bX, bY;

    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        for(int j = 0; j < m; j++)
        {
            board[i][j] = s[j];

            if(board[i][j] == 'R')
            {
                rX = i;
                rY = j;
                board[i][j] = '.';
                
            }

            else if(board[i][j] == 'B')
            {
                bX = i;
                bY = j;
                board[i][j] = '.';
            }
        }
    }

    cout << BFS(rX, rY, bX, bY) << "\n";


    return 0;
}
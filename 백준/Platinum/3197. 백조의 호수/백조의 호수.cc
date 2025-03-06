#include <bits/stdc++.h>

using namespace std;

int r, c;

char board[1600][1600];


int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// 현재 물 큐, 다음 물 큐, 현재 백조 큐, 다음 백조 큐
queue<pair<int, int>> waterQ, waterNQ, swanQ, swanNQ;

bool vis[1600][1600];

void MeltIce()
{
    while(!waterQ.empty())
    {
        auto [curX, curY] = waterQ.front();
        waterQ.pop();

        for(int i = 0; i < 4; i++)
        {
            int nX = curX + dx[i];
            int nY = curY + dy[i];

            if(nX < 0 || nX >= r || nY < 0 | nY >= c) continue;

            // 물 큐에서 방문확인할 필요 없는 이유?
            // 빙판 => 물로 바뀐 곳은 이미 .으로 바뀌어서 재방문 할 수 없음
            if(board[nX][nY] == 'X')
            {
                board[nX][nY] = '.';
                waterNQ.push({nX, nY});
            }
        }
        
    }
}

bool CanReach()
{
    while(!swanQ.empty())
    {
        auto [curX, curY] = swanQ.front();
        swanQ.pop();

        for(int i = 0; i < 4; i++)
        {
            int nX = curX + dx[i];
            int nY = curY + dy[i];

            if(nX < 0 || nX >= r || nY < 0 || nY >= c) continue;
            if(vis[nX][nY]) continue;

            if(board[nX][nY] == '.')
            {
                vis[nX][nY] = true;
                swanQ.push({nX, nY});
            }
            else if(board[nX][nY] == 'X')
            {
                vis[nX][nY] = true;
                swanNQ.push({nX, nY});
            }
            else
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c;

    for(int i = 0; i < r; i++)
    {
        string s;
        cin >> s;
        for(int j = 0; j < c; j++)
        {
            board[i][j] = s[j];

            // 백조가 있는 곳도 물
            if(board[i][j] == 'L')
            {
                if(swanQ.empty())
                {
                    swanQ.push({i, j});
                    vis[i][j] = true;
                }
            }

            if(board[i][j] != 'X')
            {
                waterQ.push({i, j});
                
            }
        }
    }
    
    int ans = 0;
    while(true)
    {
        if(CanReach())
        {
            break;
        }

        MeltIce();
        // 다음 방문할 곳으로 큐 업데이트
        swanQ = swanNQ;
        waterQ = waterNQ;

        while(!swanNQ.empty()) swanNQ.pop();
        while(!waterNQ.empty()) waterNQ.pop();

        ans++;
    }

    cout << ans << "\n";

    return 0;
}
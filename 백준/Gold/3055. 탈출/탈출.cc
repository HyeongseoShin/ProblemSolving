#include <bits/stdc++.h>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int r, c;

char board[51][51];

int water[51][51];
int dist[51][51];

int stX, stY, goalX, goalY;

queue<pair<int, int>> waterQ;

void waterBFS()
{
    while(!waterQ.empty())
    {
        auto [curX, curY] = waterQ.front();
        waterQ.pop();

        for(int i = 0; i < 4; i++)
        {
            int nX = curX + dx[i];
            int nY = curY + dy[i];

            if(nX < 0 || nX >= r || nY < 0 || nY >= c) continue;
            if(board[nX][nY] == 'X') continue;
            if(board[nX][nY] == 'D') continue;
            if(water[nX][nY] != -1) continue;

            water[nX][nY] = water[curX][curY] + 1;
            waterQ.push({nX, nY});
        }
    }
}

void BFS(int x, int y)
{
    queue<pair<int, int>> q;
    dist[x][y] = 0;
    q.push({x, y});

    while(!q.empty())
    {
        auto [curX, curY] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nX = curX + dx[i];
            int nY = curY + dy[i];

            if(nX < 0 || nX >= r || nY < 0 || nY >= c) continue;
            if(board[nX][nY] == 'X') continue;
            if(dist[nX][nY] != -1) continue;
            if(water[nX][nY] != -1 && dist[curX][curY] + 1 >= water[nX][nY]) continue;

            dist[nX][nY] = dist[curX][curY] + 1;
            q.push({nX, nY});
        }
    }
}

int main()
{
    ios::sync_with_stdio();
    cin.tie(0);

    cin >> r >> c;

    memset(water, -1, sizeof(water));
    memset(dist, -1, sizeof(dist));

    for(int i = 0; i < r; i++)
    {
        string s;
        cin >> s;

        for(int j = 0; j < c; j++)
        {
            board[i][j] = s[j];

            if(board[i][j] == 'S')
            {
                stX = i;
                stY = j;
            }

            else if(board[i][j] == 'D')
            {
                goalX = i;
                goalY = j;
            }

            else if(board[i][j] == '*')
            {
                water[i][j] = 0;
                waterQ.push({i, j});
            }
        }
    }

    waterBFS();

    // for(int i = 0; i < r; i++)
    // {
    //     for(int j = 0; j < c; j++)
    //     {
    //         cout << setw(2) << water[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    // cout << "\n=============\n";

    BFS(stX, stY);

    // for(int i = 0; i < r; i++)
    // {
    //     for(int j = 0; j < c; j++)
    //     {
    //         cout << setw(2) << dist[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    if(dist[goalX][goalY] == -1)
    {
        cout << "KAKTUS" << "\n";
        return 0;
    }

    cout << dist[goalX][goalY] << "\n";

    return 0;
}
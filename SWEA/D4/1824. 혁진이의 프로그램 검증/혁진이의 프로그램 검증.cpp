#include <bits/stdc++.h>

using namespace std;

int r, c;

char board[20][20];

// x좌표, y좌표, 들어온 방향, 메모리
bool vis[20][20][4][16];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool BFS()
{
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push({{0, 0}, {1, 0}});

    vis[0][0][1][0] = true;

    while(!q.empty())
    {
        auto [x, y] = q.front().first;
        auto [dir, mem] = q.front().second;

        q.pop();

        if(board[x][y] == '@') return true;

        else if(board[x][y] == '<') dir = 0;
        else if(board[x][y] == '>') dir = 1;
        else if(board[x][y] == '^') dir = 2;
        else if(board[x][y] == 'v') dir = 3;

        else if(board[x][y] == '_') dir = (mem == 0) ? 1 : 0;
        else if(board[x][y] == '|') dir = (mem == 0) ? 3 : 2;

        else if(board[x][y] >= '0' && board[x][y] <= '9') mem = board[x][y] - '0';
        
        else if(board[x][y] == '+')
        {
            mem++;
            if(mem >= 16) mem = 0;
        }
        else if(board[x][y] == '-')
        {
            mem--;
            if(mem < 0) mem = 15;
        }

        if(board[x][y] != '?')
        {
            int nX = x + dx[dir];
            int nY = y + dy[dir];

            if(nX < 0) nX = r - 1;
            else if(nX >= r) nX = 0;
            
            if(nY < 0) nY = c - 1;
            else if(nY >= c) nY = 0;

            if(vis[nX][nY][dir][mem]) continue;
            
            vis[nX][nY][dir][mem] = true;
            q.push({{nX, nY}, {dir, mem}});
        }

        else
        {
            for(int i = 0; i < 4; i++)
            {
                int nX = x + dx[i];
                int nY = y + dy[i];

                if(nX < 0) nX = r - 1;
                else if(nX >= r) nX = 0;
                
                if(nY < 0) nY = c - 1;
                else if(nY >= c) nY = 0;

                if(vis[nX][nY][i][mem]) continue;
                
                vis[nX][nY][i][mem] = true;
                q.push({{nX, nY}, {i, mem}});
            }
        }
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int testCase;
    cin >> testCase;

    for(int t = 1; t <= testCase; t++)
    {
        cin >> r >> c;

        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                cin >> board[i][j];
            }
        }

        memset(vis, false, sizeof(vis));

        cout << "#" << t << " ";
        if(BFS()) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
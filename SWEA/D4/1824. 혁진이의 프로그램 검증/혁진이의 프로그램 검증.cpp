#include <bits/stdc++.h>

using namespace std;

int r, c;

// 우, 좌, 상, 하
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

char board[20][20];

bool isPossible = false;

// 방문 확인 배열
// [x좌표][y좌표][진행방향][메모리값]
bool vis[20][20][4][16];

bool BFS()
{
    // <x, y> <dir, memory>
    queue<pair<pair<int,int>, pair<int,int>>> q;

    
    vis[0][0][0][0] = true;

    q.push({{0, 0}, {0, 0}});

    while(!q.empty())
    {
        auto [x, y] = q.front().first;
        auto [dir, memory] = q.front().second;

        if(board[x][y] == '@') return true;

        q.pop();

        char op = board[x][y];

        if(op == '<') dir = 1;
        else if(op == '>') dir = 0;
        else if(op == '^') dir = 2;
        else if(op == 'v') dir = 3;

        else if(op == '_') dir = (memory == 0) ? 0 : 1;
        else if(op == '|') dir = (memory == 0) ? 3 : 2;
        
        else if(op >= '0' && op <= '9') memory = op - '0';

        else if(op == '+') memory = (memory + 1) % 16;
        else if(op == '-')
        {
            memory--;
            if(memory < 0) memory = 15;
        }

        if(op == '?')
        {
            for(int i = 0; i < 4; i++)
            {
                int nX = x + dx[i];
                int nY = y + dy[i];

                if(nX < 0) nX = r - 1;
                else if(nX >= r) nX = 0;

                if(nY < 0) nY = c - 1;
                else if (nY >= c) nY = 0;

                if(vis[nX][nY][i][memory]) continue;

                vis[nX][nY][i][memory] = true;
                q.push({{nX, nY}, {i, memory}});
            }
        }
        else
        {
            x += dx[dir];
            y += dy[dir];

            if(x < 0) x = r - 1;
            else if(x >= r) x = 0;

            if(y < 0) y = c - 1;
            else if (y >= c) y = 0;

            if(vis[x][y][dir][memory]) continue;

            vis[x][y][dir][memory] = true;
            q.push({{x, y}, {dir, memory}});
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
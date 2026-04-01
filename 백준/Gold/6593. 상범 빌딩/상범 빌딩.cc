#include <bits/stdc++.h>

using namespace std;


int l, r, c;
char board[50][50][50];

int dz[6] = {0, 0, 0, 0, -1, 1};
int dx[6] = {0, 0, -1, 1, 0, 0};
int dy[6] = {-1, 1, 0, 0, 0, 0};

int dist[50][50][50];

int stZ, stX, stY;

int bfs(int z, int x, int y)
{
    memset(dist, -1, sizeof(dist));
    dist[z][x][y] = 0;
    queue<tuple<int, int, int>> q;

    int ans = -1;

    q.push({z, x, y});

    while(!q.empty())
    {
        auto [curZ, curX, curY] = q.front();
        q.pop();

        if(board[curZ][curX][curY] == 'E')
        {
            ans = dist[curZ][curX][curY];
            break;
        }

        for(int i = 0; i < 6; i++)
        {
            int nZ = curZ + dz[i];
            int nX = curX + dx[i];
            int nY = curY + dy[i];

            if(nZ < 0 || nZ >= l || nX < 0 || nX >= r || nY < 0 || nY >= c) continue; // 범위 벗어남
            if(board[nZ][nX][nY] == '#') continue; // 벽이면 못 감
            if(dist[nZ][nX][nY] > -1) continue; // 재방문

            dist[nZ][nX][nY] = dist[curZ][curX][curY] + 1;

            q.push({nZ, nX, nY});
            
        }
    }

    return ans;
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(true) {
        cin >> l >> r >> c;

        if(l == 0) break;

        for(int k = 0; k < l; k++)
        {
            for(int i = 0; i < r; i++)
            {
                string s;
                cin >> s;

                for(int j = 0; j < c; j++)
                {
                    board[k][i][j] = s[j];

                    if(board[k][i][j] == 'S')
                    {
                        stZ = k;
                        stX = i;
                        stY = j;
                    }
                }
            }
        }

        int ans = bfs(stZ, stX, stY);

        if(ans == -1) cout << "Trapped!\n";
        else cout << "Escaped in " << ans << " minute(s).\n";
        
    }

    return 0;
}
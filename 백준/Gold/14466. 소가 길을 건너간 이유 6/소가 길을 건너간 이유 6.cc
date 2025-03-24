#include <bits/stdc++.h>

using namespace std;

int n, k, r;

// bridge[i][j][n] : (i,j) 의 n방향에 다리가 있음

int bridge[103][103][4];
int cow [103][103];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool vis[103][103];

int ans = 0;

void BFS(int x, int y)
{
    vis[x][y] = true;

    queue<pair<int, int>> q;
    q.push({x, y});

    while(!q.empty())
    {
        auto [curX, curY] = q.front();
        q.pop();

        // cout << "curX: " << curX << " curY: " << curY << "\n";

        for(int i = 0; i < 4; i++)
        {
            int nX = curX + dx[i];
            int nY = curY + dy[i];

            if(nX < 1 || nX > n || nY < 1 || nY > n) continue;
            if(vis[nX][nY]) continue;
            if(bridge[curX][curY][i] == 1) continue;

            vis[nX][nY] = true;
            q.push({nX, nY});

            if(cow[nX][nY] == 1)
            {
                // cout << x << " " << y << " " << nX << " " << nY << "\n"; 
                ans++;
            }
        }
    }
    
}

void Init()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            vis[i][j] = false;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k >> r;

    for(int i = 0; i < r; i++)
    {
        int r1, c1, r2, c2;

        cin >> r1 >> c1 >> r2 >> c2;

        for(int j = 0; j < 4; j++)
        {
            int nX = r1 + dx[j];
            int nY = c1 + dy[j];

            if(nX == r2 && nY == c2)
            {
                bridge[r1][c1][j] = 1;
                
                // 연결된 다리 표시
                if(j % 2 == 0) bridge[r2][c2][j+1] = 1;
                else bridge[r2][c2][j-1] = 1;
            }
        }

        

    }

    for(int i = 0; i < k; i++)
    {
        int x, y;

        cin >> x >> y;

        cow[x][y] = 1;

    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(cow[i][j] == 1)
            {
                // cout << "start: " << " x : " << i << " y : " << j << "\n";
                Init();
                BFS(i, j);
                
            }
        }

        // cout << "\n=====================\n";
        // for(int x = 1; x <= n; x++)
        // {
        //     for(int y = 1; y <= n; y++)
        //     {
        //         cout << vis[x][y] << " ";
        //     }
        //     cout << "\n";
        // }
        
    }

    ans = (k * (k-1) - ans) / 2;

    cout << ans << "\n";

    

    return 0;
}
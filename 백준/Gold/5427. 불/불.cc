#include <bits/stdc++.h>

using namespace std;

char board[1001][1001];
int t, w, h;

int posX, posY;

queue<pair<int, int>> fire;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int ans = INT_MAX;

int dist[1001][1001];

void FireBFS()
{
    while(!fire.empty())
    {
        auto [curX, curY] = fire.front();
        fire.pop();

        for(int i = 0; i < 4; i++)
        {
            int nX = curX + dx[i];
            int nY = curY + dy[i];

            if(nX < 0 || nX >= h || nY < 0 || nY >= w) continue;
            if(board[nX][nY] == '#') continue;
            if(dist[nX][nY] != -1) continue;

            dist[nX][nY] = dist[curX][curY] + 1;
            fire.push({nX, nY});
        }
    }
}

void BFS()
{
    int dist2[1001][1001];
    memset(dist2, -1, sizeof(dist2));
    dist2[posX][posY] = 0;

    queue<pair<int, int>> q;
    q.push({posX, posY});

    while(!q.empty())
    {
        // 상근이 BFS 진행
        auto [curX, curY] = q.front();
        q.pop();

        if(curX == 0 || curX == h - 1 || curY == 0 || curY == w - 1)
        {
            // cout << "curX: " << curX << " curY: " << curY << " dist[curX][curY]: " << dist[curX][curY] << "\n";
            ans = dist2[curX][curY] + 1;
            break;
        }

        for(int i = 0; i < 4; i++)
        {
            int nX = curX + dx[i];
            int nY = curY + dy[i];

            if(nX < 0 || nX >= h || nY < 0 || nY >= w) continue;
            if(board[nX][nY] == '#' || board[nX][nY] == '#') continue;
            if(dist[nX][nY] != -1 && dist2[curX][curY] + 1 >= dist[nX][nY]) continue;
            if(dist2[nX][nY] != -1) continue;

            dist2[nX][nY] = dist2[curX][curY] + 1;
            q.push({nX, nY});
        }
    }

    // cout << "\n================\n";
    // for(int i = 0; i < h; i++)
    // {
    //     for(int j = 0; j < w; j++)
    //     {
    //         cout << setw(2) << dist2[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> w >> h;
        
        ans = INT_MAX;
        memset(dist, -1, sizeof(dist));
        while(!fire.empty()) fire.pop();

        for(int i = 0; i < h; i++)
        {
            string s;
            cin >> s;

            for(int j = 0; j < w; j++)
            {
                board[i][j] = s[j];

                if(board[i][j] == '@')
                {
                    posX = i;
                    posY = j;
                }
                else if(board[i][j] == '*')
                {
                    fire.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        FireBFS();
        BFS();

        if(ans == INT_MAX)
        {
            cout << "IMPOSSIBLE\n";
        }
        else cout << ans << "\n";
    }

    return 0;
}
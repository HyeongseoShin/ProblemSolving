#include <bits/stdc++.h>

using namespace std;

int n, k, r;

// 다리 표시
int bridge[105][105];

// 각 칸에 소 위치
int cowPos[105][105];

// 방문 확인
bool vis[105][105];

// 소 위치
vector<pair<int, int>> cows;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int ans = 0;

void BFS(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    vis[x][y] = true;

    while(!q.empty())
    {
        auto [curX, curY] = q.front();
        q.pop();

        // cout << "curX: " << curX << " curY: " << curY << "\n";

        for(int i = 0; i < 4; i++)
        {
            // cout << "bridge: " << bridge[curX][curY] << "\n";
            if((bridge[curX][curY] >> i) & 1) continue;
            
            int nX = curX + dx[i];
            int nY = curY + dy[i];

            if(nX < 1 || nX > n || nY < 1 || nY > n) continue;
            if(vis[nX][nY]) continue;
            if(cowPos[nX][nY] != 0)
            {
                ans++;
                // cout << "출발 : " << cowPos[x][y] << " 도착: " << cowPos[nX][nY] << "\n";
            }

            vis[nX][nY] = true;
            q.push({nX, nY});
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
            if((r2 - r1) == dx[j] && (c2 - c1) == dy[j])
            {
                bridge[r1][c1] += (1 << j);

                if(j % 2 == 0) bridge[r2][c2] += (1 << (j+1));
                else bridge[r2][c2] += (1 << (j-1));
            }
        }
    }

    for(int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        
        cows.push_back({x, y});
        cowPos[x][y] = (i+1);
    }

    for(int i = 0; i < k; i++)
    {
        auto [x, y] = cows[i];
        
        memset(vis, false, sizeof(vis));
        BFS(x, y);
    }

    cout << ((k * (k-1)) - ans) / 2 << "\n";

    return 0;
}
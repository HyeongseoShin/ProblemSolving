#include <bits/stdc++.h>

using namespace std;

int n, m;

int cheese[105][105];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int cnt = 0;

bool vis[105][105];

// 외부 공기 BFS로 찾기
void FindOutAir(int x, int y)
{
    queue<pair<int, int>> q;
    vis[x][y] = true;

    q.push({x, y});

    while(!q.empty())
    {
        auto [curX, curY] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nX = curX + dx[i];
            int nY = curY + dy[i];

            if(nX < 0 || nX >= n || nY < 0 || nY >= m) continue;
            if(vis[nX][nY]) continue;
            if(cheese[nX][nY] == 1) continue;
            
            // 외부 공기는 -1로 만들기
            cheese[nX][nY] = -1;
            vis[nX][nY] = true;
            q.push({nX, nY});
        }
    }
}

void RemoveCheese()
{
    queue<pair<int, int>> q;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(cheese[i][j] == 1)
            {
                int airCnt = 0;
                for(int dir = 0; dir < 4; dir++)
                {
                    int nX = i + dx[dir];
                    int nY = j + dy[dir];

                    if(cheese[nX][nY] == -1) airCnt++;
                }

                if(airCnt >= 2) q.push({i, j});
            }
        }
    }

    while(!q.empty())
    {
        auto [curX, curY] = q.front();
        q.pop();

        cheese[curX][curY] = 0;
        cnt--;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> cheese[i][j];

            if(cheese[i][j] == 1) cnt++;
        }
    }

    int ans = 0;
    while(cnt > 0)
    {
        ans++;
        // 2차원 배열 초기화
        memset(vis, 0, sizeof(vis));
        FindOutAir(0, 0);
        RemoveCheese();
    }

    cout << ans << "\n";

    return 0;
}
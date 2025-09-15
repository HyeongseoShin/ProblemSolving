#include <bits/stdc++.h>

using namespace std;

// 0 : 빈 칸, 1 : 벽, 2 : 바이러스
int board[51][51];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int n, m;

vector<pair<int,int>> virusPos; // 바이러스 위치 저장
bool isSelected[11]; // 해당 바이러스가 선택되었는지 확인

int ans = INT_MAX;

int BFS()
{
    int dist[51][51];
    memset(dist, -1, sizeof(dist));

    queue<pair<int, int>> q;

    int maxDist = 0;

    // 바이러스 활성화
    for(int i = 0; i < (int)virusPos.size(); i++)
    {
        if(!isSelected[i]) continue;
        auto [x, y] = virusPos[i];

        dist[x][y] = 0;
        q.push({x, y});
    }

    while(!q.empty())
    {
        auto [curX, curY] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nX = curX + dx[i];
            int nY = curY + dy[i];

            if(nX < 0 || nX >= n || nY < 0 || nY >= n) continue;
            if(board[nX][nY] == 1) continue; // 벽이면 pass
            if(dist[nX][nY] != -1) continue; // 방문했으면 pass

            dist[nX][nY] = dist[curX][curY] + 1;

            if(board[nX][nY] == 0) maxDist = max(maxDist, dist[nX][nY]);

            q.push({nX, nY});
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(board[i][j] == 0 && dist[i][j] == -1) return INT_MAX;
        }
    }
    
    return maxDist;


}

void DFS(int idx, int cnt)
{
    if(cnt == m)
    {
        // BFS() 시작
        ans = min(ans, BFS());
        return;
    }

    for(int i = idx; i < (int)virusPos.size(); i++)
    {
        isSelected[i] = true;
        DFS(i + 1, cnt + 1);
        isSelected[i] = false;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> board[i][j];

            if(board[i][j] == 2) virusPos.push_back({i, j});
        }
    }

    DFS(0, 0);

    if(ans == INT_MAX) ans = -1;
    cout << ans << "\n";

    return 0;
}
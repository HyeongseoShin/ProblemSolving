#include <bits/stdc++.h>

using namespace std;

int m, n;

// 벽 현황
int board[55][55];

// 방 번호 표시
int room[55][55];

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

// 각 방의 크기
vector<int> area;

bool vis[55][55];

// 가장 큰 방의 크기
int maxArea = 0;

// 벽 하나 부쉈을 때 만들 수 있는 최대 방 크기
int sumArea = 0;

void MakeRoom(int x, int y, int idx)
{
    int cnt = 0;

    queue<pair<int, int>> q;
    q.push({x, y});

    room[x][y] = idx;

    while(!q.empty())
    {
        auto [curX, curY] = q.front();
        q.pop();
        cnt++;

        int curV = board[curX][curY];

        for(int i = 0; i < 4; i++)
        {
            // 현재 자리가 1이면 Pass
            if((curV >> i) & 1) continue;

            int nX = curX + dx[i];
            int nY = curY + dy[i];

            if(nX < 0 || nX >= n || nY < 0 || nY >= m) continue;
            
            // 이미 방 부여 되어있으면 Pass
            if(room[nX][nY] != 0) continue;
            room[nX][nY] = idx;
            q.push({nX, nY});
        }
    }

    maxArea = max(maxArea, cnt);
    area.push_back(cnt);
}

void GetsumArea(int x, int y, int idx)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    
    vis[x][y] = true;

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

            // 같은 방이면 계속 탐색
            if(room[nX][nY] == idx)
            {
                vis[nX][nY] = true;
                q.push({nX, nY});
            }

            // 다른 방이면 방 2개 합친 크기 구하기
            else
            {   
                sumArea = max(sumArea, area[idx-1] + area[room[nX][nY] - 1]);
            }

        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }

    // 방 개수
    int roomIdx = 1;

    // 방 나누기 & 각 방의 크기 저장
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            // 이미 방이 부여된 곳
            if(room[i][j] != 0) continue;
            MakeRoom(i, j, roomIdx++);
        }
    }

    // 하나의 벽을 제거해서 얻을 수 있는 가장 넓은 방의 크기 구하기
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(vis[i][j]) continue;
            GetsumArea(i, j, room[i][j]);
        }
    }

    cout << roomIdx - 1 << "\n";
    cout << maxArea << "\n";
    cout << sumArea << "\n";

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int n, m;

int board[301][301];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int ans = 0;

int iceCnt = 0;
bool isDivided = false;

int posX = -1, posY = -1;

void meltIce()
{
    int newBoard[301][301];
    memset(newBoard, 0, sizeof(newBoard));

    // BFS에서 처음 출발할 얼음 위치 지정
    posX = -1;
    posY = -1;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            // 바다면 pass
            if(board[i][j] == 0) continue;

            int seaCnt = 0; // 인접해 있는 바다 개수
            for(int dir = 0; dir < 4; dir++)
            {
                int nX = i + dx[dir];
                int nY = j + dy[dir];

                if(nX < 0 || nX >= n || nY < 0 || nY >= m) continue;

                if(board[nX][nY] == 0) seaCnt++; // 바다 개수 업데이트
            }

            newBoard[i][j] = seaCnt;
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(board[i][j] == 0) continue;

            board[i][j] -= newBoard[i][j];

            if(board[i][j] <= 0)
            {
                iceCnt--;
                board[i][j] = 0;
            }

            else if(posX == -1 && posY == -1)
            {
                posX = i;
                posY = j;
            }
        }
    }

    // cout << "\n==========\n";
    // for(int i = 0; i < n; i++)
    // {
    //     for(int j = 0; j < m; j++)
    //     {
    //         cout << board[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
}

bool checkDivision()
{
    // 출발 지점 없으면 종료
    if(posX == -1 && posY == -1) return true;

    queue<pair<int, int>> q;
    q.push({posX, posY});

    bool vis[301][301];
    memset(vis, false, sizeof(vis));
    vis[posX][posY] = true;

    int cnt = 1; // 방문한 얼음 칸 개수

    while(!q.empty())
    {
        auto [curX, curY] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nX = curX + dx[i];
            int nY = curY + dy[i];

            if(nX < 0 || nX >= n || nY < 0 || nY >= m) continue;
            if(board[nX][nY] == 0) continue;
            if(vis[nX][nY]) continue;

            vis[nX][nY] = true;
            q.push({nX, nY});
            cnt++;
        }
    }

    // cout << "cnt: " << cnt << " iceCnt: " << iceCnt << "\n";
    // 아직 빙하가 하나로 이어져 있음
    if(iceCnt == cnt) return false;

    // 빙하가 분리됨
    else return true;
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
            cin >> board[i][j];

            if(board[i][j] > 0) iceCnt++;
        }
    }

    while(true)
    {
        ans++;

        meltIce();

        if(iceCnt == 0) 
        {
            // cout << "얼음 다 녹음\n";
            break;
        }

        if(checkDivision()) 
        {
            // cout << "빙하 나눠짐\n";
            break;
        }
    }

    if(iceCnt == 0) ans = 0;
    cout << ans << "\n";

    return 0;
}
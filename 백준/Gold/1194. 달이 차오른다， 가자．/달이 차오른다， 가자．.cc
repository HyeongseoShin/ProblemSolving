#include <bits/stdc++.h>

using namespace std;

int n, m;

char board[51][51];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int mX = -1, mY = -1;

// dist[i][j][k] : (i, j)에 k 열쇠 보유 상태인 채로 방문한 적 있는지 확인
int dist[51][51][(1 << 6)];

int ans = INT_MAX;

void BFS()
{
    memset(dist, -1, sizeof(dist));
    dist[mX][mY][0] = 0;
    
    // <x, y, 열쇠 상태>
    queue<tuple<int, int, int>> q;
    q.push({mX, mY, 0});

    while(!q.empty())
    {
        auto [curX, curY, curS] = q.front();
        q.pop();

        // 도착
        if(board[curX][curY] == '1')
        {
            ans = dist[curX][curY][curS];
            return;
        }

        for(int i = 0; i < 4; i++)
        {
            int nX = curX + dx[i];
            int nY = curY + dy[i];
            int nS = curS;

            // 범위 확인
            if(nX < 0 || nX >= n || nY < 0 || nY >= m) continue;
            
            // 벽이면 Pass
            if(board[nX][nY] == '#') continue;

            // 이미 같은 열쇠 상태로 재방문이면 Pass
            if(dist[nX][nY][curS] != -1) continue;

            // 문이면 열쇠 없으면 Pass
            if(board[nX][nY] >= 'A' && board[nX][nY] <= 'F')
            {
                // 현재 문 번호
                int curDoor = board[nX][nY] - 'A';

                // 현재 문에 해당하는 열쇠 가지고 있는지 확인
                // 없으면 Pass
                if(((curS >> curDoor) & 1) == 0) continue;
            } 
            
            // 열쇠이면 획득
            if(board[nX][nY] >= 'a' && board[nX][nY] <= 'f')
            {
                int curKey = board[nX][nY] - 'a';

                int checkKey = (1 << curKey);

                nS = (nS | checkKey);
            }

            dist[nX][nY][nS] = dist[curX][curY][curS] + 1;
            q.push({nX, nY, nS});
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for(int j = 0; j < m; j++)
        {
            board[i][j] = s[j];
            
            if(board[i][j] == '0')
            {
                mX = i;
                mY = j;
            }
        }
    }

    BFS();

    if(ans == INT_MAX) ans = -1;
    cout << ans << "\n";

    return 0;
}
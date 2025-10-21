#include <bits/stdc++.h>

using namespace std;

int n, m, k;

int board[1001][1001];

// (x, y) 오는데까지 벽을 k번 부쉈고 현재 낮 or 밤일때 최단 거리
// 0 : 낮
// 1 : 밤
int dist[1001][1001][11][2];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int ans = INT_MAX;

void BFS()
{
    // x, y, 벽 부순 횟수, 낮 밤 여부
    queue<tuple<int, int, int, int>> q;
    // 낮부터 시작
    q.push({0, 0, 0, 0});

    dist[0][0][0][0] = 1;

    while(!q.empty())
    {
        auto [curX, curY, curCnt, curDay] = q.front();
        q.pop();

        // 도착하면 끝
        if(curX == n - 1 && curY == m - 1)
        {
            ans = dist[curX][curY][curCnt][curDay];
            return;
        }

        for(int i = 0; i < 4; i++)
        {
            int nX = curX + dx[i];
            int nY = curY + dy[i];
            int nCnt = curCnt;
            int nDay = 1 - curDay; // 0 -> 1 / 1 -> 0

            if(nX < 0 || nX >= n || nY < 0 || nY >= m) continue; // 범위 벗어나면 패스
            
            if(board[nX][nY] == 1) // 벽일 때
            {
                nCnt = curCnt + 1;
                if(nCnt > k) continue; // 벽 부순 횟수 넘으면 벽 못 부숨

                // 밤이라면 낮 될때까지 기다리기
                if(curDay == 1) 
                {
                    if(dist[nX][nY][curCnt][nDay] != -1) continue; // 이미 방문했으면 패스

                    dist[curX][curY][curCnt][nDay] = dist[curX][curY][curCnt][curDay] + 1;
                    q.push({curX, curY, curCnt, nDay});
                    continue;
                }
                
            }

            if(dist[nX][nY][nCnt][nDay] != -1) continue; // 이미 방문했으면 패스

            dist[nX][nY][nCnt][nDay] = dist[curX][curY][curCnt][curDay] + 1;
            q.push({nX, nY, nCnt, nDay});
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        for(int j = 0; j < m; j++)
        {
            // 입력 예제 틀린 원인
            // 문자열 -> 숫자로 바꿀 때는 꼭 - '0' 해주자
            board[i][j] = s[j] - '0';
        }
    }

    // 최단 거리 배열 초기화
    memset(dist, -1, sizeof(dist));

    BFS();

    if(ans == INT_MAX) ans = -1;
    cout << ans << "\n";

    return 0;
}
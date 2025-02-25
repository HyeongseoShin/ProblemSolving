#include <bits/stdc++.h>

using namespace std;

int n, m;

int board[10][10];
vector<pair<int, int>> camPos; // cctv 위치 저장

int ans = 100;
int walCnt = 0;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

// CCTV 방향별 검사
void Check(int x, int y, int dir)
{
    dir %= 4; // 방향 설정

    int nX = x;
    int nY = y;

    while(true)
    {
        nX = nX + dx[dir];
        nY = nY + dy[dir];

        if(nX < 0 || nX >= n || nY < 0 || nY >= m || board[nX][nY] == 6) break;
        if(board[nX][nY] != 0) continue;

        board[nX][nY] = 7; // CCTV 커버 가능 범위 표시
    }
}

// 백트래킹 & 시뮬레이션
void Scan(int idx)
{
    if(idx == camPos.size())
    {
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                // cout << board[i][j] << " ";
                if(board[i][j] == 0) cnt++;
            }
            // cout << "\n";
        }
        
        ans = min(ans, cnt);

        // cout << "===================\n\n";
        return ;
    }

    int tmp[10][10];

    auto [curX, curY] = camPos[idx];

    for(int dir = 0; dir < 4; dir++)
    {
        // 원본 배열 저장해놓기
        for(int i = 0; i < n; i++)
        {
            for(int j = 0;j < m; j++)
            {
                tmp[i][j] = board[i][j];
            }
        }

        if(board[curX][curY] == 1)
        {
            Check(curX, curY, dir);
        }

        else if(board[curX][curY] == 2)
        {
            Check(curX, curY, dir);
            Check(curX, curY, dir + 2);
        }

        else if(board[curX][curY] == 3)
        {
            Check(curX, curY, dir);
            Check(curX, curY, dir + 1);
        }

        else if(board[curX][curY] == 4)
        {
            Check(curX, curY, dir);
            Check(curX, curY, dir + 1);
            Check(curX, curY, dir + 2);
            
        }

        else if(board[curX][curY] == 5)
        {
            Check(curX, curY, dir);
            Check(curX, curY, dir + 1);
            Check(curX, curY, dir + 2);
            Check(curX, curY, dir + 3);
            
        }

        Scan(idx+1);

        // 원본 배열 복구
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                board[i][j] = tmp[i][j];
            }
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
        for(int j = 0; j < m;j++)
        {
            cin >> board[i][j];

            // cctv 위치 저장
            if(board[i][j] >= 1 && board[i][j] <= 5) camPos.push_back({i, j});
        }
    }

    Scan(0);

    cout << ans << "\n";

    return 0;


}
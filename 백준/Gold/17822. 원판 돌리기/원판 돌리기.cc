#include <bits/stdc++.h>

using namespace std;

// 원판 번호, 원판에 있는 숫자의 수, 회전 횟수
int n, m, t;

int board[53][53];

int ans = 0;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void printBoard()
{
    cout << "\n\n";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

// d : 0 => 시계 방향
// d : 1 => 반시계 방향
void rotate(int x, int d, int k)
{
    int tmp[53];

    for(int i = 0; i < m; i++)
    {
        tmp[i] = board[x][i];
    }

    int dir = d;

    // 시계 방향이면 진행 방향 -1
    if(dir == 0) dir = -1;

    for(int i = 0; i < m; i++)
    {
        int idx = (i + (dir * k)) % m;
        if(idx < 0) idx += m;

        board[x][i] = tmp[idx];
    }
}

void deleteNearNum()
{
    vector<pair<int, int>> delPos;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            bool isDeleted = false;
            // 삭제된 수이면 패스
            if(board[i][j] == 0) continue;

            for(int dir = 0; dir < 4; dir++)
            {
                int nX = i + dx[dir];
                int nY = (j + dy[dir]) % m;

                if(nX < 0 || nX >= n || nY < 0 || nY >= m) continue;

                if(board[i][j] == board[nX][nY])
                {
                    // cout << "i: " << i << " j: " << j << " nX: " << nX << " nY: " << nY << "\n";
                    delPos.push_back({nX, nY});
                    isDeleted = true;
                }
            }

            if(isDeleted)
            {
                delPos.push_back({i, j});
            }
        }
    }

    if((int)delPos.size() > 0)
    {
        for(auto [i, j] : delPos)
        {
            // cout << "i: " << i << " j: " << j << "\n";
            board[i][j] = 0;
        }

        return;
    }
    

    double avg = 0.0;
    int sum = 0;
    int cnt = 0;
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(board[i][j] == 0) continue;

            sum += board[i][j];
            cnt++;
        }
    }
    

    avg = (double)sum / (double)cnt;
    // cout << "avg: " << avg << "\n";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(board[i][j] == 0) continue;

            if(board[i][j] > avg) board[i][j]--;
            
            else if(board[i][j] < avg) board[i][j]++;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> t;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }

    // printBoard();

    while(t--)
    {
        int x, d, k;
        
        cin >> x >> d >> k;

        for(int i = 0 + (x - 1); i < n; i += x)
        {
            rotate(i, d, k);
        }

        // cout << "after rotate\n";
        // printBoard();
        
        deleteNearNum();

        // cout << "after delete\n";
        // printBoard();
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            ans += board[i][j];
        }
    }

    cout << ans << "\n";

    return 0;
}
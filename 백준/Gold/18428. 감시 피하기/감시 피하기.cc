#include <bits/stdc++.h>

using namespace std;

int n;

char board[7][7];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

vector<pair<int, int>> tPos; // 선생 위치
vector<pair<int, int>> xPos; // 빈 칸 위치 (장애물 설치 후보)

bool isPossible()
{
    for(auto [x, y] : tPos)
    {
        for(int dir = 0; dir < 4; dir++)
        {
            int nX = x;
            int nY = y;

            while(true)
            {
                nX += dx[dir];
                nY += dy[dir];

                if(nX < 0 || nX >= n || nY < 0 || nY >= n) break;
                if(board[nX][nY] == 'O') break;
                if(board[nX][nY] == 'S') return false;
            }
        }
    }

    return true;
}

// 백트래킹
void getAns(int idx, int cnt)
{
    if(cnt == 3)
    {
        if(isPossible())
        {
            cout << "YES\n";
            exit(0);
        }

        return;
    }

    for(int i = idx; i < (int)xPos.size(); i++)
    {
        auto [x, y] = xPos[i];

        board[x][y] = 'O';
        getAns(i+1, cnt+1);
        board[x][y] = 'X';
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> board[i][j];

            if(board[i][j] == 'T') tPos.push_back({i, j});
            else if(board[i][j] == 'X') xPos.push_back({i, j});
        }
    }

    getAns(0, 0);

    cout << "NO\n";

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int n;

char board[10][10];

vector<pair<int, int>> tPos;
vector<pair<int, int>> oPos;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool isPossible = false;

// 선생이 학생 볼 수 있는지 검사
bool Check()
{
    for(int k = 0; k < (int)tPos.size(); k++)
    {
        auto [curX, curY] = tPos[k];

        for(int dir = 0; dir < 4; dir++)
        {
            int nX = curX;
            int nY = curY;

            while(nX >= 0 && nX < n && nY >= 0 && nY < n)
            {
                nX = nX + dx[dir];
                nY = nY + dy[dir];

                if(board[nX][nY] == 'O') break;
                if(board[nX][nY] == 'S') return false;
            }
        }
    }
    

    return true;
}

void SetObstacles(int idx, int cnt)
{
    // 장애물 3개 설치했으면 끝
    if(cnt == 3)
    {        
        // 검사
        isPossible = Check();
        return;
    }

    for(int k = idx; k < (int)oPos.size(); k++)
    {
        if(isPossible) return;

        auto [curX, curY] = oPos[k];

        board[curX][curY] = 'O';

        SetObstacles(k + 1, cnt + 1);

        board[curX][curY] = 'X';
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

            if(board[i][j] == 'X') oPos.push_back({i, j});
            if(board[i][j] == 'T') tPos.push_back({i, j});
        }
    }

    SetObstacles(0, 0);

    if(isPossible) cout << "YES\n";
    else cout << "NO\n";

    return 0;

}
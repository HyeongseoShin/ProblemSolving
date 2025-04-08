#include <bits/stdc++.h>

using namespace std;

int r, c;

int dx[10] = {0, 1, 1, 1, 0, 0, 0, -1, -1, -1};
int dy[10] = {0, -1, 0, 1, -1, 0, 1, -1, 0, 1};

char board[105][105];

// 종수 위치
int jX, jY;

// 아두이노 위치
vector<pair<int, int>> aduino;

int ans = 1;
bool isGameEnded = false;

int aduinoStatus[105][105];

// 아두이노 이동
void MoveAduino()
{
    if(isGameEnded) return;

    for(int i = 0; i < (int)aduino.size(); i++)
    {
        auto [curX, curY] = aduino[i];

        // 없어진 아두이노면 패스
        if(board[curX][curY] != 'R') continue;

        int minDist = 500;
        int closeX = curX;
        int closeY = curY;

        for(int dir = 1; dir < 10; dir++)
        {
            int nX = curX + dx[dir];
            int nY = curY + dy[dir];

            if(nX < 0 || nX >= r || nY < 0 || nY >= c) continue;
            
            // 가장 가까운 방향 구하기
            if(minDist > (abs(jX - nX) + abs(jY - nY)))
            {
                minDist = (abs(jX - nX) + abs(jY - nY));
                
                closeX = nX;
                closeY = nY;
            }
            
        }

        // 종수 만나면 게임 끝
        if(board[closeX][closeY] == 'I')
        {
            isGameEnded = true;
            return;
        }

        // 일단 아두이노 이동
        else
        {
            aduinoStatus[closeX][closeY]++;
        }
    }

    aduino.clear();
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(aduinoStatus[i][j] == 1)
            {
                aduino.push_back({i, j});
                board[i][j] = 'R';
            }

            else board[i][j] = '.';

            aduinoStatus[i][j] = 0;
        }
    }

    board[jX][jY] = 'I';
}

// 종수 이동
void MoveJongsu(int curDir)
{
    board[jX][jY] = '.';

    jX += dx[curDir];
    jY += dy[curDir];

    // 아두이노 만나면 게임 끝
    if(board[jX][jY] == 'R')
    {
        isGameEnded = true;
        return;
    }

    board[jX][jY] = 'I';
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c;

    for(int i = 0; i < r; i++)
    {
        string s;
        cin >> s;

        for(int j = 0; j < c; j++)
        {
            board[i][j] = s[j];

            if(board[i][j] == 'I')
            {
                jX = i;
                jY = j;
            }

            else if(board[i][j] == 'R')
            {
                aduino.push_back({i, j});
                // aduinoStatus[i][j]++;
            }
        }
    }

    string dir;
    cin >> dir;

    for(int i = 0; i < (int)dir.length(); i++)
    {
        // 현재 방향
        int curDir = dir[i] - '0';

        // 종수 이동
        MoveJongsu(curDir);

        // 아두이노 이동
        MoveAduino();

        // cout << "\n====================\n";
        // for(int k = 0; k < r; k++)
        // {
        //     for(int j = 0; j < c; j++)
        //     {
        //         cout << board[k][j];
        //     }
        //     cout << "\n";
        // }
        // cout << "====================\n";

        

        if(isGameEnded) break;
        ans++;
    }

    if(isGameEnded) cout << "kraj " << ans << "\n";

    else
    {
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                cout << board[i][j];
            }
            cout << "\n";
        }
    }



    return 0;
}
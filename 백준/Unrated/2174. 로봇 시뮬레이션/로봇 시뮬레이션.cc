#include <bits/stdc++.h>

using namespace std;

// L : -1
// R : +1

// N, E, S, W
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

// 각 로봇별 <좌표, 방향> 저장
tuple<int, int, int> robotPos[105];

int a, b, n, m;

// 로봇이 위치하면 >= 1 없으면 0
int board[105][105];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;
    cin >> n >> m;

    // 로봇 위치 저장
    for(int i = 1; i <= n; i++)
    {
        int x, y;
        char dir;

        cin >> x >> y >> dir;

        // 해당 칸에 로봇 위치
        board[x][y] = i;

        switch(dir)
        {
            case 'N':
                robotPos[i] = {x, y, 0};
                break;
            case 'E':
                robotPos[i] = {x, y, 1};
                break;
            case 'S':
                robotPos[i] = {x, y, 2};
                break;
            case 'W':
                robotPos[i] = {x, y, 3};
                break;
        }
    }

    // 명령 수행
    while(m--)
    {
        int num;
        char op;
        int cnt;

        cin >> num >> op >> cnt;

        auto [curX, curY, curDir] = robotPos[num];

        if(op == 'L')
        {
            while(cnt--)
            {
                curDir = (curDir + 3) % 4;
                robotPos[num] = {curX, curY, curDir};
            }
            
        }

        else if(op == 'R')
        {
            while(cnt--)
            {
                curDir = (curDir + 1) % 4;
                robotPos[num] = {curX, curY, curDir};
            }
            
        }
        
        else
        {
            int nX = curX;
            int nY = curY;

            while(cnt--)
            {
                board[nX][nY] = 0;
                nX += dx[curDir];
                nY += dy[curDir];

                // 벽임
                if(nX < 1 || nX > a || nY < 1 || nY > b)
                {
                    cout << "Robot " << num << " crashes into the wall\n";
                    exit(0);
                }

                // 다른 로봇 마주침
                if(board[nX][nY] != 0)
                {
                    cout << "Robot " << num << " crashes into robot " << board[nX][nY] << "\n";
                    exit(0);
                }

                // 앞으로 이동
                
                board[nX][nY] = num;
                robotPos[num] = {nX, nY, curDir};
                
            }
        }
    }

    cout << "OK\n";

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int n;

// 현재 모래 현황
int board[500][500];

// 격자 밖으로 나간 모래의 양
int ans = 0;

// 좌, 하, 우, 상
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

// 모래 흩날리는 비율 담은 배열
int leftSand[5][5] = {
    {0, 0, 2, 0, 0},
    {0, 10, 7, 1, 0},
    {5, -1, 0, 0, 0},
    {0, 10, 7, 1, 0},
    {0, 0, 2, 0, 0},
};

int downSand[5][5] = {
    {0, 0, 0, 0, 0},
    {0, 1, 0, 1, 0},
    {2, 7, 0, 7, 2},
    {0, 10, -1, 10, 0},
    {0, 0, 5, 0, 0},
};

int rightSand[5][5] = {
    {0, 0, 2, 0, 0},
    {0, 1, 7, 10, 0},
    {0, 0, 0, -1, 5},
    {0, 1, 7, 10, 0},
    {0, 0, 2, 0, 0},
};

int upSand[5][5] = {
    {0, 0, 5, 0, 0},
    {0, 10, -1, 10, 0},
    {2, 7, 0, 7, 2},
    {0, 1, 0, 1, 0},
    {0, 0, 0, 0, 0}
};

// 모래 흩날리기
void spreadSand(int x, int y, int dir)
{
    int sand[5][5];

    // 진행 방향에 따른 모래 흩날리는 배열 회전
    if(dir == 0) memcpy(sand, leftSand, sizeof(sand));
    if(dir == 1) memcpy(sand, downSand, sizeof(sand));
    if(dir == 2) memcpy(sand, rightSand, sizeof(sand));
    if(dir == 3) memcpy(sand, upSand, sizeof(sand));

    
    int sandAmount = board[x][y];
    board[x][y] = 0; // 모래 전부 퍼질 예정

    int spreadSum = 0;
    int aX = -1, aY = -1;

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if(sand[i][j] == 0) continue;
            
            int nX = x + (i - 2);
            int nY = y + (j - 2);

            // 알파 칸이면 좌표만 저장
            if(sand[i][j] == -1)
            {
                aX = nX;
                aY = nY;
                continue;
            }

            int spread = sandAmount * sand[i][j] / 100;
            spreadSum += spread;

            // 격자 밖으로 나간 모래
            if(nX < 0 || nX >= n || nY < 0 || nY >= n) ans += spread;

            // 격자 안이면 모래 퍼짐
            else board[nX][nY] += spread;
        }
    }

    // 남은 모래
    int remain = sandAmount - spreadSum;

    // 알파가 격자 밖이면
    if(aX < 0 || aX >= n || aY < 0 || aY >= n)
    {
        ans += remain;
    }

    // 격자 안이면 그 칸에 남은 모래 삽입
    else
    {
        board[aX][aY] += remain;
    }

}

// 토네이도 이동
void moveTornado()
{
    // 출발점
    int curX = n / 2;
    int curY = n / 2;

    int step = 1; // 현재 나아가야할 스텝
    int dir = 0; // 현재 방향
    int cnt = 0; // 같은 방향으로 진행한 횟수

    // 토네이도 진행
    while(true)
    {
        for(int i = 0; i < step; i++)
        {
            curX += dx[dir];
            curY += dy[dir];

            spreadSand(curX, curY, dir);

            if(curX == 0 && curY == 0)
            {
                return;
            }
        }

        // 방향 전환
        dir = (dir + 1) % 4;
        
        // 진행 횟수
        cnt++;

        if(cnt == 2)
        {
            step++;
            cnt = 0;
        }
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
        }
    }

    moveTornado();

    cout << ans << "\n";

    return 0;
}
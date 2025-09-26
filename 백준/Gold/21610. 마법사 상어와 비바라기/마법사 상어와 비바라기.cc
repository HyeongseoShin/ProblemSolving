// https://www.acmicpc.net/problem/21610

#include <bits/stdc++.h>

using namespace std;

// 1 ~ 8까지 방향 진행
int dx[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int dy[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};

int n, m;

int board[51][51]; // 바구니에 담긴 물의 양 정보

int cloudCnt[51][51]; // 각 칸에 있는 구름 개수

// 구름 위치
queue<pair<int, int>> cloudPos;

void printBoard()
{
    cout << "\n=========\n";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

// 방향, 칸
void moveCloud(int d, int s)
{
    int sz = (int)cloudPos.size();

    while(sz--)
    {
        auto [x, y] = cloudPos.front();
        cloudPos.pop();

        int nX = (x + (dx[d] * s));
        int nY = (y + (dy[d] * s));

        // 끝과 끝 연결
        if(nX >= n) nX %= n;
        else if(nX < 0)
        {
            nX = x;
            for(int i = 0; i < s; i++)
            {
                nX += dx[d];
                if(nX < 0) nX = n - 1;
            }
        }
        
        if(nY >= n) nY %= n;
        else if(nY < 0)
        {
            nY = y;
            for(int i = 0; i < s; i++)
            {
                nY += dy[d];
                if(nY < 0) nY = n - 1;
            }
        }

        cloudCnt[x][y]--; // 기존 칸에 구름 하나 없어짐
        cloudCnt[nX][nY]++; // 새로운 구름 자리 옮김

        board[nX][nY]++; // 물 양 ++

        // cout << "curX: " << x << " curY: " << y << " nX: " << nX << " nY: " << nY << "\n";

        cloudPos.push({nX, nY}); // 구름 이동 위치 저장
    }

    // cout << "구름 크기 : " << (int)cloudPos.size() << "\n";

    // 모든 구름이 사라진다.
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cloudCnt[i][j] = 0;
        }
    }

    // memset(isCloud, false, sizeof(isCloud));

    vector<pair<int,int>> deletedClouds; // 3에서 사라진 구름 위치 저장

    // 2에서 물의 양이 증가한 칸 = 3에서 구름이 사라진 칸
    while(!cloudPos.empty())
    {
        auto [curX, curY] = cloudPos.front();
        cloudPos.pop();

        // 사라진 구름 위치 저장
        deletedClouds.push_back({curX, curY});

        int cnt = 0; // 대각선 1칸에 물이 있는 바구니의 수 구하기
        for(int i = 2; i <= 8; i += 2)
        {
            int nX = curX + dx[i];
            int nY = curY + dy[i];

            if(nX < 0 || nX >= n || nY < 0 || nY >= n) continue; // 범위 밖이면 패스
            if(board[nX][nY] > 0) cnt++; // 바구니에 물 차있으면 ++
        }

        board[curX][curY] += cnt; // 대각선 1거리에 물 차있는 바구니 수만큼 물 양 증가
    }

    // cout << "구름 크기 : " << (int)deletedClouds.size() << "\n";

    // printBoard();    

    // 바구니에 저장된 물의 양이 2 이상인 모든 칸에 구름이 생기고 물의 양이 2가 줄어든다.
    // 구름이 생기는 칸은 3에서 구름이 사라진 칸이 아니어야 함
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            // 현재 칸이 3번에서 구름 사라진 위치라면
            bool isDeleted = false;
            for(int tmp = 0; tmp < (int)deletedClouds.size(); tmp++)
            {
                auto [tmpX, tmpY] = deletedClouds[tmp];
                // cout << "기존 구름 위치: " << tmpX << " " << tmpY << "\n";
                if(i == tmpX && j == tmpY)
                {
                    isDeleted = true;
                    break;
                }
            }

            if(isDeleted) continue;

            // 3에서 사라진 구름 위치 지정
            if(board[i][j] >= 2)
            {
                // 아니라면 구름 생성
                // 물 양 -= 2
                cloudCnt[i][j]++;
                board[i][j] -= 2;
                cloudPos.push({i, j});

                // cout << "새로운 구름 위치: " << i << " " << j << "\n";
            }
        }
    }

    // printBoard();

    // cout << "size: " << (int)cloudPos.size() << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    // 바구니에 물 담기
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }

    // 비바라기 시전
    // isCloud[n-1][0] = true;
    // isCloud[n-1][1] = true;
    // isCloud[n-2][0] = true;
    // isCloud[n-2][1] = true;

    // 비구름 위치 저장
    cloudPos.push({n-1, 0});
    cloudPos.push({n-1, 1});
    cloudPos.push({n-2, 0});
    cloudPos.push({n-2, 1});

    // 각 칸에 구름 개수 ++
    cloudCnt[n-1][0]++;
    cloudCnt[n-1][1]++;
    cloudCnt[n-2][0]++;
    cloudCnt[n-2][1]++;

    while(m--)
    {
        // 방향, 칸 개수
        int d, s;

        cin >> d >> s;

        moveCloud(d, s);
    }

    // printBoard();

    int ans = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            ans += board[i][j];
        }
    }

    cout << ans << "\n";

    return 0;
}

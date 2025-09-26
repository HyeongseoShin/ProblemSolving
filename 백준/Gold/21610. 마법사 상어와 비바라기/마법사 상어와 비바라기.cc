#include <bits/stdc++.h>

using namespace std;

// 1 ~ 8까지 방향 진행
int dx[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int dy[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};

int n, m;

int board[51][51]; // 바구니에 담긴 물의 양 정보
bool isDeleted[51][51]; // 구름이 삭제된 칸인지 확인

// 구름 위치
queue<pair<int, int>> cloudPos;

// 방향, 칸
void moveCloud(int d, int s)
{
    int sz = (int)cloudPos.size();

    while(sz--)
    {
        auto [x, y] = cloudPos.front();
        cloudPos.pop();

        int nX = (x + (dx[d] * s)) % n;
        int nY = (y + (dy[d] * s)) % n;

        // 끝과 끝 연결
        if(nX < 0) nX += n;
        if(nY < 0) nY += n;

        board[nX][nY]++; // 물 양 ++

        cloudPos.push({nX, nY}); // 구름 이동 위치 저장
    }

    // 모든 구름이 사라진다.
    // 구름 삭제된 적 있는지 확인하는 배열 초기화
    memset(isDeleted, false, sizeof(isDeleted));

    // 2에서 물의 양이 증가한 칸 = 3에서 구름이 사라진 칸
    while(!cloudPos.empty())
    {
        auto [curX, curY] = cloudPos.front();
        cloudPos.pop();

        // 사라진 구름 위치 저장
        isDeleted[curX][curY] = true;

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

    // 바구니에 저장된 물의 양이 2 이상인 모든 칸에 구름이 생기고 물의 양이 2가 줄어든다.
    // 구름이 생기는 칸은 3에서 구름이 사라진 칸이 아니어야 함
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            // 3에서 사라진 구름 위치이면 패스
            if(isDeleted[i][j]) continue;

            if(board[i][j] >= 2)
            {
                // 아니라면 구름 생성
                // 물 양 -= 2
                board[i][j] -= 2;
                cloudPos.push({i, j});
            }
        }
    }
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
    // 비구름 위치 저장
    cloudPos.push({n-1, 0});
    cloudPos.push({n-1, 1});
    cloudPos.push({n-2, 0});
    cloudPos.push({n-2, 1});

    while(m--)
    {
        // 방향, 칸 개수
        int d, s;

        cin >> d >> s;

        moveCloud(d, s);
    }

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
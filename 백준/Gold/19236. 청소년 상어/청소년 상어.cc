// https://www.acmicpc.net/problem/19236

#include <bits/stdc++.h>
using namespace std;

// fishPos[num] : 번호가 num인 물고기의 <x, y> 좌표
pair<int, int> fishPos[17];

// board[i][j] : (i, j) 위치의 <물고기 번호, 방향>
pair<int,int> board[4][4];

// 방향 : 0 ~ 7 (반시계)
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};

int ans = 0;

// 물고기 이동 함수
void moveFish(pair<int,int> b[4][4], pair<int,int> f[17], int sharkX, int sharkY) {
    for(int i = 1; i <= 16; i++) {
        auto [curX, curY] = f[i];
        if(curX == -1) continue; // 이미 먹힌 물고기

        int dir = b[curX][curY].second;

        for(int j = 0; j < 8; j++) {
            int nDir = (dir + j) % 8;
            int nX = curX + dx[nDir];
            int nY = curY + dy[nDir];

            if(nX < 0 || nX >= 4 || nY < 0 || nY >= 4) continue;
            if(nX == sharkX && nY == sharkY) continue;

            auto [otherFish, otherDir] = b[nX][nY];

            // swap 물고기
            if(otherFish != 0) {
                swap(f[i], f[otherFish]);
                swap(b[curX][curY], b[nX][nY]);
                b[nX][nY].second = nDir;
            }
            // 빈 칸 이동
            else {
                b[nX][nY] = {i, nDir};
                b[curX][curY] = {0, 0};
                f[i] = {nX, nY};
            }
            break;
        }
    }
}

// DFS 탐색
void dfs(pair<int,int> b[4][4], pair<int,int> f[17], int sharkX, int sharkY, int sharkDir, int sum) {
    ans = max(ans, sum);

    // 1. 물고기 이동
    moveFish(b, f, sharkX, sharkY);

    // 2. 상어 이동 (1~3칸)
    for(int step = 1; step <= 3; step++) {
        int nX = sharkX + dx[sharkDir] * step;
        int nY = sharkY + dy[sharkDir] * step;

        if(nX < 0 || nX >= 4 || nY < 0 || nY >= 4) break;
        if(b[nX][nY].first == 0) continue; // 물고기 없으면 이동 불가

        // 상태 복사
        pair<int,int> newBoard[4][4];
        pair<int,int> newFish[17];
        memcpy(newBoard, b, sizeof(newBoard));
        memcpy(newFish, f, sizeof(newFish));

        int fishNum = newBoard[nX][nY].first;
        int fishDir = newBoard[nX][nY].second;

        // 물고기 먹음
        newBoard[nX][nY] = {0, 0};
        newFish[fishNum] = {-1, -1};

        dfs(newBoard, newFish, nX, nY, fishDir, sum + fishNum);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            int num, dir;
            cin >> num >> dir;
            fishPos[num] = {i, j};
            board[i][j] = {num, dir - 1};
        }
    }

    // (0,0) 물고기 먹기
    int firstFish = board[0][0].first;
    int firstDir = board[0][0].second;

    board[0][0] = {0, 0};
    fishPos[firstFish] = {-1, -1};

    dfs(board, fishPos, 0, 0, firstDir, firstFish);

    cout << ans << "\n";
    return 0;
}

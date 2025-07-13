#include <bits/stdc++.h>
using namespace std;

struct Shark {
    int s, d, z; // 속력, 방향, 크기
};

int R, C, M;
int dx[] = {0, -1, 1, 0, 0}; // 위, 아래, 오른쪽, 왼쪽
int dy[] = {0, 0, 0, 1, -1};

Shark board[101][101];

void moveSharks() {
    Shark newBoard[101][101] = {};

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            Shark &shark = board[i][j];
            if (shark.z == 0) continue;

            int x = i, y = j;
            int s = shark.s, d = shark.d, z = shark.z;

            // 이동 최적화
            if (d == 1 || d == 2) s %= (2 * (R - 1));
            else s %= (2 * (C - 1));

            while (s--) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 1 || nx > R || ny < 1 || ny > C) {
                    if (d == 1) d = 2;
                    else if (d == 2) d = 1;
                    else if (d == 3) d = 4;
                    else if (d == 4) d = 3;

                    nx = x + dx[d];
                    ny = y + dy[d];
                }

                x = nx;
                y = ny;
            }

            // 겹치면 크기 비교
            if (newBoard[x][y].z < z)
                newBoard[x][y] = {shark.s, d, z};
        }
    }

    // board 갱신
    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++)
            board[i][j] = newBoard[i][j];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> R >> C >> M;

    for (int i = 0; i < M; i++) {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        board[r][c] = {s, d, z};
    }

    int answer = 0;

    for (int col = 1; col <= C; col++) {
        // 1. 낚시왕이 상어 잡기
        for (int row = 1; row <= R; row++) {
            if (board[row][col].z > 0) {
                answer += board[row][col].z;
                board[row][col] = {0, 0, 0}; // 잡힘
                break;
            }
        }

        // 2. 상어 이동
        moveSharks();
    }

    cout << answer << '\n';
    return 0;
}

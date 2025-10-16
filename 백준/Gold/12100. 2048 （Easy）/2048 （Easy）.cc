#include <bits/stdc++.h>

using namespace std;

int n;

int board[25][25];
int board2[25][25];

// 2차원 배열 시계 방향 90도 회전하는 함수
void Rotate() {
    int tmp[25][25];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            tmp[i][j] = board2[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            board2[i][j] = tmp[n - 1 - j][i];
        }
    }
}

void Tilt(int dir) {
    // 기본적으로 좌측으로 기울이는 것을 기준!
    // 각 방향마다 기울이는 코드를 쓰는 것이 아니라 
    // 배열을 회전시킨 것을 왼쪽으로 기울이는 것으로 함

    // 0 : 좌
    // 1: 상
    // 2: 우
    // 3 : 하
    while(dir--) {
        Rotate();
    }

    for(int i = 0; i < n; i++) {
        // board2를 기울인 결과 저장할 변수
        int tilted[25] = {};

        int idx = 0;

        for(int j = 0 ; j < n; j++) {
            if(board2[i][j] == 0) {
                continue;
            }

            else if(tilted[idx] == 0) {
                tilted[idx] = board2[i][j];
            }

            else if(tilted[idx] == board2[i][j]) {
                tilted[idx++] *= 2;
            }

            else {
                tilted[++idx] = board2[i][j];
            }
        }

        for(int j = 0; j < n; j++) {
            board2[i][j] = tilted[j];
        }

    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    int ans = 0;

    // 4 ^ 5승 = 총 1024개의 경우의 수
    for(int l = 0; l < (1 << (2 * 5)); l++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                board2[i][j] = board[i][j];
            }
        }

        int brute = l;

        // 최대 5번 이동
        for(int i = 0; i < 5; i++) {
            int dir = brute % 4;
            brute /= 4;

            Tilt(dir);
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                ans = max(ans, board2[i][j]);
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
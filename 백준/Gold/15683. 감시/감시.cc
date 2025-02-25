#include <bits/stdc++.h>

using namespace std;

int n, m;

// 원본 입력 배열
int arr[10][10];

// CCTV마다 검사 가능 타일을 표시하기 위한 임시 배열
int arr2[10][10];

int dx[4] = {1, 0, -1, 0}; // 하 우 상 좌
int dy[4] = {0, 1, 0, -1}; // 하 우 상 좌

// CCTV의 위치 저장
vector<pair<int, int>> cctv;

// 사각 지대의 최소 크기
int ans = 0;

// 좌표의 범위 검사
bool OOB(int x, int y) {
    return x < 0 || x >= n || y < 0 || y >= m;
}

// (x,y)에서 dir 방향으로 진행하면서 벽을 만날 떄까지 7로 만들어주기
void upd(int x, int y, int dir) {

    // 방향이 4를 넘을 경우 (0 ~ 3)의 범위로 다시 조정
    dir %= 4;

    while(true) {
        int nextX = x + dx[dir];
        int nextY = y + dy[dir];

        // cout << "nextX: " << nextX << " nextY: " << nextY << "\n";

        // 현재 (x, y)가 유효한 좌표가 아니거나 벽이면 break
        if(OOB(nextX, nextY) || arr2[nextX][nextY] == 6) {
            break;
        }

        // 현재 (x, y)가 0이 아니면 (CCTV이거나 이미 7이면) continue (해당 타일을 7로 만들어주지 않음)
        else if(arr2[nextX][nextY] != 0) {
            x += dx[dir];
            y += dy[dir];
            continue;
        }

        // 모든 조건을 통과하면 해당 칸을 7로 만들어줌 (CCTV 검사 가능 타일)
        arr2[nextX][nextY] = 7;

        x += dx[dir];
        y += dy[dir];
        
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
            
            // CCTV라면 vector에 추가
            if(arr[i][j] != 0 && arr[i][j] != 6) {
                cctv.push_back({i, j});
            }

            // 0이면 사각지대 크기 ++
            else if(arr[i][j] == 0) {
                ans++;
            }
        }
    }

    // 한 CCTV당 갈 수 있는 방향 => 4가지 => 상하좌우 => 4진법으로 표기
    // 1 << 2*cctv.size() == 4 ^ cctv.size()의 경우의 수
    for(int k = 0; k < (1 << (2 * cctv.size())); k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                // 타일 검사 배열에 원본 배열 값 복사
                arr2[i][j] = arr[i][j];
            }
        }

        // 현재 CCTV들의 방향
        int brute = k;

        // cctv 개수에 따라 방향 뽑아내기
        for(int i = 0; i < cctv.size(); i++) {
            // 현재 cctv의 방향
            int dir = brute % 4;

            // 다음 방향 뽑기 위해 brute 조정
            brute /= 4;

            int x = cctv[i].first;
            int y = cctv[i].second;

            // 1번 CCTV 한 방향만 가능
            if(arr[x][y] == 1) {
                upd(x, y, dir);
            }

            // 2번 CCTV 두 방향 가능 (반대)
            else if(arr[x][y] == 2) {
                upd(x, y, dir);
                upd(x, y, dir + 2);
            }

            // 3번 CCTV 두 방향 가능 (직각)
            else if(arr[x][y] == 3) {
                upd(x, y, dir);
                upd(x, y, dir + 1);
            }

            // 4번 CCTV 세 방향 가능
            else if(arr[x][y] == 4) {
                upd(x, y, dir);
                upd(x, y, dir + 1);
                upd(x, y, dir + 2);
            }

            // 5번 CCTV 모든 방향 가능
            else if(arr[x][y] == 5) {
                upd(x, y, dir);
                upd(x, y, dir + 1);
                upd(x, y, dir + 2);
                upd(x, y, dir + 3);
            }
        }

        // 모두 검사를 마친 후 arr2에 0의 개수를 구하고
        // ans와 비교해 더 적은 값을 정답으로 정함
        int tmp = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(arr2[i][j] == 0) {
                    tmp++;
                }
            }
        }

        ans = min(ans, tmp);
    }

    cout << ans << "\n";

    return 0;
}
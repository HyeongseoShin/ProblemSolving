#include <bits/stdc++.h>
#include <climits>

using namespace std;

int r, c;

char place[1001][1001];

int JTime[1001][1001]; // 지훈이가 이동가능한 시간
int FTime[1001][1001]; // 불길이 번지는 시간

int dx[4] = {1, 0, -1, 0}; // 우 하 좌 상
int dy[4] = {0, 1, 0, -1}; // 우 하 좌 상

void BFS(bool isFire);


queue<pair<int, int>> q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c;

    // 불길 BFS 준비
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> place[i][j];

            JTime[i][j] = -1;
            FTime[i][j] = -1;

            if(place[i][j] == 'F') {
                FTime[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    // 불에 대한 BFS 먼저
    BFS(true);

    q = {};

    // 지훈이 BFS 준비 => J는 하나
    bool isFindJ = false;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(place[i][j] == 'J') {
                JTime[i][j] = 0;
                q.push({i, j});
                isFindJ = true;
                break;
            }
        }

        if(isFindJ) {
            break;
        }
    }

    // 지훈이 BFS
    BFS(false);

    int escapeTime = INT_MAX;
   
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            // 84% 틀렸습니다 원인 => 벽이 없을 수도 있고, place[i][j] == J인 경우도 지훈이가 지나갈 수 있음
            if(place[i][j] == '#' || place[i][j] == 'F') {
                continue;
            }

            else if(!(i == 0 || i == r - 1 || j == 0 || j == c - 1)) {
                continue;
            }

            // 61% 틀렸습니다 원인 => FTime[i][j] == -1인 경우에는 불길이 아예 번지지 않아서 이 경우도 추가해주어야 함
            if(JTime[i][j] != -1 && ((JTime[i][j] < FTime[i][j]) || FTime[i][j] == -1)) {
                // cout << "JTime: " << JTime[i][j] << " FTime: " << FTime[i][j] << "\n";
                escapeTime = min(escapeTime, JTime[i][j]);
            }
        }
    }

    if(escapeTime == INT_MAX) {
        cout << "IMPOSSIBLE\n";
    }
    else {
        cout << escapeTime + 1 << "\n";
    }

    return 0;
}

void BFS(bool isFire) {
    while(!q.empty()) {
        int curX = q.front().first;
        int curY = q.front().second;

        q.pop();

        for(int i = 0; i < 4; i++) {
            int newX = curX + dx[i];
            int newY = curY + dy[i];

            if(newX < 0 || newX >= r || newY < 0 || newY >= c) {
                continue;
            }

            // 불이라면
            else if(isFire) {
                if((FTime[newX][newY] != -1 || place[newX][newY] != '.')) {
                    continue;
                }
                FTime[newX][newY] = FTime[curX][curY] + 1;
                q.push({newX, newY});
            }

            // 지훈이라면
            else if(!isFire) {
                if((JTime[newX][newY] != -1 || place[newX][newY] != '.')) {
                    continue;
                }
                JTime[newX][newY] = JTime[curX][curY] + 1;
                q.push({newX, newY});
            }
        }
    }
}
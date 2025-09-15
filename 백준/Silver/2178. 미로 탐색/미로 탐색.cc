#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int maze[100][100];
bool visited[100][100] = {false};
queue<pair<int, int>> queueBFS; // (x, y좌표)
void BFS(int x, int y);
static int n, m; // 배열의 세로 길이, 가로 길이;
vector<pair<int, int>> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}}; // 상하좌우 방향 표시

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < m; j++) {
            maze[i][j] = s[j] - '0';
        }
    }
    
    BFS(0, 0);
    cout << maze[n-1][m-1] << "\n";
    
    return 0;
}

void BFS(int x, int y) {
    queueBFS.push(pair(x,y));
    visited[x][y] = true;

    while(!queueBFS.empty()) {
        pair<int,int> front = queueBFS.front();
        x = front.first;
        y = front.second;
        queueBFS.pop();

        visited[x][y] = true;

        for(int i = 0; i < dir.size(); i++) {
            int dx = dir[i].first;
            int dy = dir[i].second;

            int newX = x + dx;
            int newY = y + dy;

            if(newX >= 0 && newX < n && newY >= 0 && newY < m) {
                if(maze[newX][newY] != 0 && !visited[newX][newY]) {
                    visited[newX][newY] = true;
                    maze[newX][newY] = maze[x][y] + 1;
                    queueBFS.push(pair(newX, newY));
                }
            } 
        }
    }
}
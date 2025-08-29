#include <bits/stdc++.h>
using namespace std;

int n, m, fuel;
int board[22][22];
int stX, stY;
int fromTo[22][22];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
map<pair<int, int>, pair<int, int>> passengerInfo;

struct Customer {
    int fromX, fromY, dist, num;
};

bool cmp(Customer A, Customer B) {
    if (A.dist != B.dist) return A.dist < B.dist;
    if (A.fromX != B.fromX) return A.fromX < B.fromX;
    return A.fromY < B.fromY;
}

Customer findNearestPassenger(int x, int y) {
    queue<tuple<int, int, int>> q;
    bool vis[21][21] = {};
    q.push({0, x, y});
    vis[x][y] = true;

    vector<Customer> customers;

    while (!q.empty()) {
        auto [curDist, curX, curY] = q.front();
        q.pop();

        if (fromTo[curX][curY] > 0) {
            customers.push_back({curX, curY, curDist, fromTo[curX][curY]});
        }

        for (int i = 0; i < 4; i++) {
            int nx = curX + dx[i];
            int ny = curY + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
            if (board[nx][ny] == 1 || vis[nx][ny]) continue;
            vis[nx][ny] = true;
            q.push({curDist + 1, nx, ny});
        }
    }

    if (customers.empty()) return {-1, -1, -1, -1};
    sort(customers.begin(), customers.end(), cmp);
    return customers[0];
}

bool moveToDestination(int fromX, int fromY, int toX, int toY) {
    int dist[21][21];
    memset(dist, -1, sizeof(dist));

    queue<pair<int, int>> q;
    q.push({fromX, fromY});
    dist[fromX][fromY] = 0;

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
            if (board[nx][ny] == 1 || dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }

    if (dist[toX][toY] == -1) {
        fuel = -1;
        return false;
    }

    int used = dist[toX][toY];
    if (fuel < used) {
        fuel = -1;
        return false;
    }

    fuel -= used;
    fuel += used * 2;
    stX = toX;
    stY = toY;

    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> fuel;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> board[i][j];

    cin >> stX >> stY;

    for (int i = 1; i <= m; i++) {
        int fromX, fromY, toX, toY;
        cin >> fromX >> fromY >> toX >> toY;
        fromTo[fromX][fromY] = i;
        passengerInfo[{fromX, fromY}] = {toX, toY};
    }

    for (int i = 0; i < m; i++) {
        auto [fromX, fromY, dist, num] = findNearestPassenger(stX, stY);
        if (num == -1 || fuel < dist) {
            fuel = -1;
            break;
        }

        fuel -= dist;
        stX = fromX;
        stY = fromY;
        fromTo[fromX][fromY] = 0;

        auto [toX, toY] = passengerInfo[{fromX, fromY}];

        if (!moveToDestination(fromX, fromY, toX, toY)) break;
    }

    cout << fuel << '\n';
    return 0;
}

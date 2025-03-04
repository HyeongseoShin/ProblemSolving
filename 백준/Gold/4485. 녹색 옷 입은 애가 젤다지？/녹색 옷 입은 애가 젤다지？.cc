#include <bits/stdc++.h>

#define MAX 1000001

using namespace std;

int cave[200][200];
int dist[200][200];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int n;

void BFS(int x, int y)
{
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

    dist[x][y] = cave[x][y];
    pq.push({dist[x][y], x, y});

    while(!pq.empty())
    {
        auto [curDist, curX, curY] = pq.top();
        pq.pop();

        for(int i = 0; i < 4; i++)
        {
            int nX = curX + dx[i];
            int nY = curY + dy[i];

            if(nX < 0 || nX >= n || nY < 0 || nY >= n) continue;

            if(dist[nX][nY] > curDist + cave[nX][nY])
            {
                dist[nX][nY] = curDist + cave[nX][nY];
                pq.push({dist[nX][nY], nX, nY});
            }
        }
    }
}

int main()
{
    int t = 1;

    while(true)
    {
        cin >> n;

        if(n == 0) break;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                dist[i][j] = MAX;
                cin >> cave[i][j];
            }
        }

        BFS(0, 0);

        cout << "Problem " << t << ": " << dist[n-1][n-1] << "\n";

        t++;
    }
}
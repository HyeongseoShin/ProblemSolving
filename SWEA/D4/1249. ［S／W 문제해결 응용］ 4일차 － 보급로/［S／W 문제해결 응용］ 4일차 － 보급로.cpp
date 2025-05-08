#include <bits/stdc++.h>

using namespace std;

int board[100][100];
int dist[100][100];
int n;

int dx[4] = {-1, 1, 0 ,0};
int dy[4] = {0, 0, -1, 1};

void Dijkstra(int x, int y)
{
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    
    dist[x][y] = 0;
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
            if(dist[nX][nY] > dist[curX][curY] + board[curX][curY])
            {
                dist[nX][nY] = dist[curX][curY] + board[curX][curY];
                pq.push({dist[nX][nY], nX, nY});
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int testCase;
    cin >> testCase;
    
    for(int t = 1; t <= testCase; t++)
    {
        cin >>  n;
        
        for(int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            
            
            for(int j = 0; j < n; j++)
            {
                board[i][j] = s[j] - '0';
                dist[i][j] = INT_MAX;
            }
            
        }
        
        Dijkstra(0, 0);
        
        cout << "#" << t << " " << dist[n-1][n-1] << "\n";
    }
    return 0;
}
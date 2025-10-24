#include <bits/stdc++.h>

using namespace std;

int n;
int board[51][51];

int cnt[51][51]; // (x,y)까지 오는데 방 바꾼 최소 횟수

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void Dijkstra()
{
    // 방 바꾼 횟수, x, y
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    pq.push({0, 0, 0});

    cnt[0][0] = 0;

    while(!pq.empty())
    {
        auto [curCnt, curX, curY] = pq.top();
        pq.pop();

        for(int i = 0; i < 4; i++)
        {
            int nX = curX + dx[i];
            int nY = curY + dy[i];

            if(nX < 0 || nX >= n || nY < 0 || nY >= n) continue;

            if(board[nX][nY] == 1)
            {
                if(cnt[nX][nY] > curCnt)
                {
                    cnt[nX][nY] = curCnt;
                    pq.push({cnt[nX][nY], nX, nY});
                }
            }

            else
            {
                if(cnt[nX][nY] > curCnt + 1)
                {
                    cnt[nX][nY] = curCnt + 1;
                    pq.push({cnt[nX][nY], nX, nY});
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        for(int j = 0; j < n; j++)
        {
            board[i][j] = s[j] - '0';
        }
    }

    // 방 바꾼 최소 횟수 초기화
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cnt[i][j] = INT_MAX;
        }
    }

    Dijkstra();

    cout << cnt[n-1][n-1] << "\n";

    return 0;
}
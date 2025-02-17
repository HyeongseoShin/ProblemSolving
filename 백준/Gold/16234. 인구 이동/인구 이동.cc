// https://www.acmicpc.net/problem/16234

// BFS

#include <bits/stdc++.h>

using namespace std;

int n, l, r;
int A[200][200];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool visited[200][200];
bool isPossible;

void BFS(int x, int y)
{
    queue<pair<int, int>> q;
    queue<pair<int, int>> path;
    
    path.push({x, y});
    q.push({x, y});

    visited[x][y] = true;

    int sum = A[x][y];
    int cnt = 1;

    while(!q.empty())
    {
        auto [curX, curY] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nX = curX + dx[i];
            int nY = curY + dy[i];

            if(nX < 0 || nX >= n || nY < 0 || nY >= n || visited[nX][nY]) continue;

            if(abs(A[curX][curY] - A[nX][nY]) >= l && abs(A[curX][curY] - A[nX][nY]) <= r)
            {
                visited[nX][nY] = true;
                sum += A[nX][nY];
                isPossible = false;
                cnt++;
                q.push({nX, nY});
                path.push({nX, nY});
            }
        }
        
    }

    while(!path.empty())
    {
        auto [curX, curY] = path.front();
        path.pop();

        // cout << "curX: " << curX << " curY: " << curY << " sum/cnt: " << sum/cnt << "\n";
        A[curX][curY] = sum / cnt;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l >> r;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
    }

    int cnt = 0;
    while(true)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                visited[i][j] = false;
            }
        }

        isPossible = true;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(!visited[i][j])
                {
                    BFS(i, j);
                }
            }
        }

        // cout << "=====================\n";
        // for(int i = 0; i < n; i++)
        // {
        //     for(int j = 0; j < n; j++)
        //     {
        //         cout << A[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

        if(isPossible) break;
        cnt++;
    }

    cout << cnt << "\n";


    return 0;
}
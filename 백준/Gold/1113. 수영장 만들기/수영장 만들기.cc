#include <bits/stdc++.h>

using namespace std;

int n, m;

int board[55][55];

int maxH = 0;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int ans = 0;

// 테두리부터 BFS로 높이 curH로 만듦 (바깥쪽 --> 안쪽으로 진행)
void BFS(int curH)
{
    queue<pair<int, int>> q;

    q.push({0, 0});
    board[0][0] = curH;

    while(!q.empty())
    {
        auto [curX, curY] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nX = curX + dx[i];
            int nY = curY + dy[i];

            if(nX < 0 || nX > n + 1 || nY < 0 || nY > m + 1) continue;

            if(board[nX][nY] < curH)
            {
                board[nX][nY] = curH;
                q.push({nX, nY});
            }
        }
    }

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;

        for(int j = 1; j <= m; j++)
        {
            board[i][j] = s[j-1] - '0';
            maxH = max(maxH, board[i][j]);
        }
    }

    for(int h = 1; h <= maxH; h++)
    {
        // 바깥쪽 --> 안쪽으로 테두리 높이 h로 변경
        BFS(h);

        // 전체 칸 순회하며 현재 h보다 작은 값에 물을 채움 (++)
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(board[i][j] < h)
                {
                    ans++;
                    board[i][j]++;     
                }
            }
        }
    }

    cout << ans << "\n";


    return 0;
}
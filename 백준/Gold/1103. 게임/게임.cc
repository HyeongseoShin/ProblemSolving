#include <bits/stdc++.h>

using namespace std;

char board[51][51];

// dp[i][j] : (i, j)에서 시작했을 때 최대로 이동할 수 있는 횟수 (메모이제이션)
int dp[51][51];

// 현재 DFS 경로에서 (x, y)가 포함되어 있는지 여부 (사이클 탐지용)
bool vis[51][51];

int n, m;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};


int DFS(int curX, int curY)
{
    // 보드 밖
    if(curX < 0 || curX >= n || curY < 0 || curY >= m) return 0;
    
    // 구멍
    if(board[curX][curY] == 'H') return 0;

    // 사이클 탐지
    if(vis[curX][curY]) {
        cout << "-1\n";
        exit(0);
    }

    int &ret = dp[curX][curY];
    // 이미 계산한 적 있다면 반환
    if(ret != -1) return ret;

    vis[curX][curY] = true;
    ret = 0;


    int step = (board[curX][curY] - '0');
    for(int i = 0; i < 4; i++)
    {
        int nX = curX + (dx[i] * step);
        int nY = curY + (dy[i] * step);

        ret = max(ret, DFS(nX, nY) + 1);
    }

    vis[curX][curY] = false;
    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        for(int j = 0; j < m; j++)
        {
            board[i][j] = s[j];
        }
    }

    memset(dp, -1, sizeof(dp));
    
    cout << DFS(0, 0) << "\n";

    return 0;
}
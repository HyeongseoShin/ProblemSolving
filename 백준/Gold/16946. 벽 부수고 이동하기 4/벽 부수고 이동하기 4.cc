#include <bits/stdc++.h>

#define MOD 10
#define MAX 1001

using namespace std;

int n, m;

int board[MAX][MAX];

// dp[i][j] : (i, j)에서 이동할 수 있는 칸의 수
int dp[MAX][MAX];

int parent[1000001];

bool vis[MAX][MAX];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void DFS(int x, int y, int p)
{
    dp[p / m][p % m]++;
    vis[x][y] = true;
    parent[x * m + y] = p;

    for(int i = 0; i < 4; i++)
    {
        int nX = x + dx[i];
        int nY = y + dy[i];

        if(nX < 0 || nX >= n || nY < 0 || nY >= m) continue;
        if(vis[nX][nY]) continue;
        if(board[nX][nY] == 1) continue;

        DFS(nX, nY, p);
    }
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
            board[i][j] = s[j] - '0';
        }
    }

    for(int i = 0; i < n * m; i++)
    {
        parent[i] = i;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(board[i][j] == 0 && parent[i*m+j] == i*m+j) DFS(i, j, i * m + j);
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(parent[i*m+j] == i*m+j) continue;

            int p = parent[i*m+j];

            dp[i][j] = dp[p / m][p % m];
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(board[i][j] == 0) continue;
            int sum = 0;
            set<int> p;
            for(int dir = 0; dir < 4; dir++)
            {
                int nX = i + dx[dir];
                int nY = j + dy[dir];

                if(nX < 0 || nX >= n || nY < 0 || nY >= m) continue;
                if(board[nX][nY] == 1) continue;
                if(p.find(parent[nX*m+nY]) != p.end()) continue;

                sum += dp[nX][nY];
                p.insert(parent[nX*m+nY]);
            }

            dp[i][j] = sum + 1;
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(board[i][j] == 0) dp[i][j] = 0;
            
            cout << dp[i][j] % MOD;
            
        }
        cout << "\n";
    }

    return 0;
}
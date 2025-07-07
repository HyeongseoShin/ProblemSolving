#include <bits/stdc++.h>

using namespace std;

int n, m;

int board[1001][1001];

// 상, 하, 좌, 우
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int parent[1000001];

int ans = 0;

int Find(int v)
{
    if(parent[v] == v) return parent[v];
    else return parent[v] = Find(parent[v]);
}

void Union(int v1, int v2)
{
    v1 = Find(v1);
    v2 = Find(v2);

    if(v1 < v2) parent[v2] = v1;
    else parent[v1] = v2;
}

void DFS(int x, int y)
{
    int dir = board[x][y];

    int nX = x + dx[dir];
    int nY = y + dy[dir];

    if(Find(x * m + y) != Find(nX * m + nY))
    {
        Union(x * m + y, nX * m + nY);
        DFS(nX, nY);
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
            int dir = 0;
            if(s[j] == 'U') dir = 0;
            else if(s[j] == 'D') dir = 1;
            else if(s[j] == 'L') dir = 2;
            else if(s[j] == 'R') dir = 3;

            board[i][j] = dir;

            parent[i * m + j] = i * m + j;
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            DFS(i, j);
        }
    }

    set<int> ans;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            ans.insert(Find(i * m + j));
        }
    }

    cout << (int) ans.size() << "\n";

    return 0;
}
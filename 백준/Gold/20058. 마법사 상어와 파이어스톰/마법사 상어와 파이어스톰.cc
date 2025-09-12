#include <bits/stdc++.h>

using namespace std;

int N, n, q;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int ice[70][70]; // 얼음의 양

int oper[1001]; // 단계 별 격자 나누는 크기 (1 << oper[i])

int ans = 0;
int maxSz = 0;

bool vis[70][70];

// 부분 격자 시계 방향으로 90도 회전
void rotate90(int x, int y, int l)
{
    // 일단 부분 격자 복사
    int newBoard[70][70];
    for(int i = 0; i < l; i++)
    {
        for(int j = 0; j < l; j++)
        {
            newBoard[i][j] = ice[x + i][y + j];
        }
    }

    // 시계 방향 90도 회전
    for(int i = 0; i < l; i++)
    {
        for(int j = 0; j < l; j++)
        {
            ice[x + j][y + l - 1 - i] = newBoard[i][j];
        }
    }

}


// 부분 격자로 나누기
void divideIces(int sz)
{
    for(int i = 0; i < N; i += sz)
    {
        for(int j = 0; j < N; j += sz)
        {
            rotate90(i, j, sz);
        }
    }
}

// 한 번에 적용
void meltIce()
{
    vector<pair<int,int>> v;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            // 얼음 칸 아니면 pass
            if(ice[i][j] <= 0) continue;
            
            int cnt = 0;
            for(int dir = 0; dir < 4; dir++)
            {
                int nX = i + dx[dir];
                int nY = j + dy[dir];

                if(nX < 0 || nX >= N || nY < 0 || nY >= N) continue;
                if(ice[nX][nY] <= 0) continue;
                cnt++;
            }

            if(cnt < 3) v.push_back({i,j});
        }
    }

    for(int i = 0; i < (int)v.size(); i++)
    {
        auto [x, y] = v[i];
        ice[x][y]--;
    }
}

void BFS(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    vis[x][y] = true;

    int sz = 1;
    ans += ice[x][y];

    while(!q.empty())
    {
        auto [curX, curY] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nX = curX + dx[i];
            int nY = curY + dy[i];

            if(nX < 0 || nX >= N || nY < 0 || nY >= N) continue;
            if(ice[nX][nY] == 0) continue;
            if(vis[nX][nY]) continue;

            sz++;
            ans += ice[nX][nY];
            vis[nX][nY] = true;
            q.push({nX, nY});
        }
    }

    maxSz = max(maxSz, sz);
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;

    N = (1 << n);

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> ice[i][j];
        }
    }

    for(int i = 0; i < q; i++)
    {
        cin >> oper[i];
    }

    for(int i = 0; i < q; i++)
    {
        // 부분 격자로 나눠서 시계 방향 90도 회전
        divideIces((1 << oper[i]));

        // 인접한 칸 검사 후 얼음 녹이기
        meltIce();
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            // 얼음 없으면 패스
            if(ice[i][j] == 0) continue;

            // 이미 방문했다면 패스
            if(vis[i][j]) continue;

            BFS(i, j);
        }
    }

    cout << ans << "\n";
    cout << maxSz << "\n";


    return 0;
}
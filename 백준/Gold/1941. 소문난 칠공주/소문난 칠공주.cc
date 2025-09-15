#include <bits/stdc++.h>

using namespace std;

char board[5][5];

int ans = 0;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool selected[25];

// 고른 자리에서 S가 4명 이상인지 확인
bool checkFour()
{
    int cnt = 0;
    for(int i = 0; i < 25; i++)
    {
        if(!selected[i]) continue;
        int x = i / 5;
        int y = i % 5;

        if(board[x][y] == 'S') cnt++;
    }

    if(cnt >= 4) return true;
    else return false;
}

// 고른 자리가 모두 인접해있는지 확인
bool BFS()
{
    bool vis[5][5];
    memset(vis, false, sizeof(vis));
    
    // 출발지 설정
    int x = -1;
    int y = -1;
    for(int i = 0; i < 25; i++)
    {
        if(selected[i])
        {
            x = i / 5;
            y = i % 5;
            
            break;
        }
    }

    queue<pair<int, int>> q;
    q.push({x, y});

    vis[x][y] = true;

    int cnt = 1;
    while(!q.empty())
    {
        auto [curX, curY] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nX = curX + dx[i];
            int nY = curY + dy[i];

            if(nX < 0 || nX >= 5 || nY < 0 || nY >= 5) continue; // 범위 확인
            if(!selected[nX * 5 + nY]) continue; // 고른 좌석인지 확인
            if(vis[nX][nY]) continue; // 방문 확인

            q.push({nX, nY});
            vis[nX][nY] = true;
            cnt++;
        }
    }

    if(cnt == 7) return true;
    else return false;

}

// 7 자리를 뽑는 모든 경우의 수
void DFS(int idx, int cnt)
{
    if(cnt == 7)
    {
        if(checkFour() && BFS()) ans++;
        return;
    }

    for(int i = idx; i < 25; i++)
    {
        selected[i] = true;
        DFS(i + 1, cnt + 1);
        selected[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 5; i++)
    {
        string s;
        cin >> s;

        for(int j = 0; j < 5; j++)
        {
            board[i][j] = s[j];
        }
    }

    DFS(0, 0);

    cout << ans << "\n";

    return 0;
}
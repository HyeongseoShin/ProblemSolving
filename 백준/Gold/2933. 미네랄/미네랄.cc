#include <bits/stdc++.h>

using namespace std;

int n, r, c;

char board[101][101];

bool vis[101][101];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void printBoard()
{
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            cout << board[i][j];
        }
        cout << "\n";
    }
}

// 공중에 있는 클러스터가 떨어졌으면 true
int BFS(int x, int y)
{
    vis[x][y] = true;

    queue<pair<int, int>> q;
    q.push({x, y});

    bool isAir = true; // 현재 클러스터가 공중에 떠있는지
    int maxX = x; // 현재 클러스터에서 가장 아래에 있는 지점의 x좌표

    vector<pair<int, int>> pos;
    pos.push_back({x, y});

    while(!q.empty())
    {
        auto [curX, curY] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nX = curX + dx[i];
            int nY = curY + dy[i];

            if(nX < 0 || nX >= r || nY < 0 || nY >= c) continue;
            if(board[nX][nY] == '.') continue;
            if(vis[nX][nY]) continue;

            // 바닥에 닿는 부분이 있으면 공중에 있는 게 아님
            if(nX == r-1) isAir = false;

            maxX = max(maxX, nX);
            pos.push_back({nX, nY});
            vis[nX][nY] = true;
            q.push({nX, nY});
        }
    }

    // 공중에 떠 있지 않으면 끝
    if(!isAir) return false;

    for(auto [pX, pY] : pos)
    {
        board[pX][pY] = '.';
    }

    int idx = 1;
    while(maxX + idx < r)
    {
        bool isPossible = true;
        for(auto [pX, pY] : pos)
        {
            if(board[pX + idx][pY] == 'x')
            {
                isPossible = false;
                break;
            }
        }

        if(!isPossible) break;
        idx++;
    }

    idx--;

    for(auto [pX, pY] : pos)
    {
        // cout << "pX: " << pX << " idx: " << idx << "\n";
        board[pX + idx][pY] = 'x';
    }

    return true;
}

// 미네랄 클러스터 떨구기
void drop()
{
    memset(vis, false, sizeof(vis));

    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(board[i][j] == '.') continue;
            if(vis[i][j]) continue;
            
            // cout << i << " " << j << "에서 시작\n";
            // 하나의 클러스터가 떨어져서 더 이상 없으므로 끝
            if(BFS(i, j)) return;
        }
    }

    // cout << "\n===========\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c;

    for(int i = 0; i < r; i++)
    {
        string s;
        cin >> s;

        for(int j = 0; j < c; j++)
        {
            board[i][j] = s[j];
        }
    }

    cin >> n;

    // 헤맨 부분
    // 한 높이에 대해 좌, 우 한 번씩 던지는 게 아니라
    // 각 높이에 대해 좌 던질 차례, 우 던질 차례 나눠져 있는 거임
    for(int i = 0; i < n; i++)
    { 
        int h;
        cin >> h;

        // 좌표 변환
        int newH = r - h;

        // 왼쪽에서 던질 차례
        if(i % 2 == 0)
        {
            for(int j = 0; j < c; j++)
            {
                if(board[newH][j] == 'x')
                {
                    board[newH][j] = '.';
                    break;
                }
            }
        }

        // 오른쪽에서 던질 차례
        else
        {
            for(int j = c - 1; j >= 0; j--)
            {
                if(board[newH][j] == 'x')
                {
                    board[newH][j] = '.';
                    break;
                }
            }
        }

        // cout << "막대 던진 후 h: " << h << " newH: " << newH << "\n";
        // printBoard();

        drop();

        // cout << "떨군 후\n";
        // printBoard();
    }

    printBoard();

    return 0;
}


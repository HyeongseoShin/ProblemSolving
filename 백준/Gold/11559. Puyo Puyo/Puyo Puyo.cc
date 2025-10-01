#include <bits/stdc++.h>

using namespace std;

char board[12][6];

int dx[4] = {-1, 1, 0 ,0};
int dy[4] = {0, 0, -1, 1};

int ans = 0;
bool vis[12][6];

void dropPuyo(int x, int y)
{
    int curX = x + 1;
    int curY = y;

    while(curX < 12 && board[curX][curY] == '.')
    {
        curX++;
    }

    curX--;

    char cur = board[x][y];
    board[x][y] = '.';
    board[curX][curY] = cur;
}

void drop()
{
    for(int i = 11; i >= 0; i--)
    {
        for(int j = 0; j < 6; j++)
        {
            if(board[i][j] == '.') continue;
            dropPuyo(i, j);
        }
    }
}

void printPuyo()
{
    cout << "\n========뿌요 출력======\n";
    for(int i = 0; i < 12; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

bool puyo(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    vis[x][y] = true;

    vector<pair<int, int>> path;
    path.push_back({x, y});

    int cnt = 1;

    while(!q.empty())
    {
        auto [curX, curY] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nX = curX + dx[i];
            int nY = curY + dy[i];

            if(nX < 0 || nX >= 12 || nY < 0 || nY >= 6) continue;
            if(board[curX][curY] != board[nX][nY]) continue;
            if(vis[nX][nY]) continue;

            vis[nX][nY] = true;
            path.push_back({nX, nY});
            q.push({nX, nY});
            cnt++;
        }
    }

    if(cnt >= 4)
    {
        for(auto [pX, pY] : path)
        {
            board[pX][pY] = '.';
        }

        return true;
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 12; i++)
    {
        string s;
        cin >> s;
        for(int j = 0; j < 6; j++)
        {
            board[i][j] = s[j];
        }
    }

    while(true)
    {
        memset(vis, false, sizeof(vis));
        bool isFinished = true;
        for(int i = 0; i < 12; i++)
        {
            for(int j = 0; j < 6; j++)
            {
                if(board[i][j] == '.') continue;
                if(vis[i][j]) continue;
                if(puyo(i, j)) isFinished = false;
            }
        }

        // cout << "뿌요 끝";
        // printPuyo();
        if(isFinished) break;

        drop();
        // cout << "떨구기 \n";
        // printPuyo();

        ans++;
    }

    cout << ans << "\n";

    return 0;
}
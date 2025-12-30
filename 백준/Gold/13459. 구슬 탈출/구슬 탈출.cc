#include <bits/stdc++.h>

using namespace std;

int n, m;

char board[11][11];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int ans = 0;

int rX, rY, bX, bY, gX, gY;
void printBoard()
{
    cout << "\n========================\n";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

// 위로 기울이기
void moveUp()
{
    for(int i = 1; i < n - 1; i++)
    {
        for(int j = 1; j < m - 1; j++)
        {
            if(board[i][j] == 'R' || board[i][j] == 'B')
            {
                char cur = board[i][j];
                board[i][j] = '.';

                int x = i;
                int y = j;

                while(board[x][y] == '.')
                {
                    x += dx[0];
                    y += dy[0];
                }

                if(board[x][y] != 'O' && board[x+1][y] != 'O') board[x+1][y] = cur;
            }
        }
    }
}


// 아래로 기울이기
void moveDown()
{
    for(int i = n - 2; i >= 1; i--)
    {
        for(int j = 1; j < m - 1; j++)
        {
            if(board[i][j] == 'R' || board[i][j] == 'B')
            {
                char cur = board[i][j];
                board[i][j] = '.';

                int x = i;
                int y = j;

                while(board[x][y] == '.')
                {
                    x += dx[1];
                    y += dy[1];
                }

                if(board[x][y] != 'O' && board[x-1][y] != 'O') board[x-1][y] = cur;
            }
        }
    }
}

// 왼쪽으로 기울이기
void moveLeft()
{
    for(int i = 1; i < m - 1; i++)
    {
        for(int j = 1; j < n - 1; j++)
        {
            if(board[j][i] == 'R' || board[j][i] == 'B')
            {
                char cur = board[j][i];
                board[j][i] = '.';

                int x = j;
                int y = i;

                while(board[x][y] == '.')
                {
                    x += dx[2];
                    y += dy[2];
                }

                if(board[x][y] != 'O' && board[x][y+1] != 'O') board[x][y+1] = cur;
            }
        }
    }
}

// 오른쪽으로 기울이기
void moveRight()
{
    for(int i = m - 2; i >= 1; i--)
    {
        for(int j = 1; j < n - 1; j++)
        {
            if(board[j][i] == 'R' || board[j][i] == 'B')
            {
                char cur = board[j][i];
                board[j][i] = '.';

                int x = j;
                int y = i;

                while(board[x][y] == '.')
                {
                    x += dx[3];
                    y += dy[3];
                }

                if(board[x][y] != 'O' && board[x][y-1] != 'O') board[x][y-1] = cur;
            }
        }
    }
}

int isFinish()
{
    bool rFound = false;
    bool bFound = false;

    // r이 없고 b가 남아 있으면 성공
    for(int i = 1; i < n - 1; i++)
    {
        for(int j = 1; j < m - 1; j++)
        {
            if(board[i][j] == 'R') rFound = true;
            else if(board[i][j] == 'B') bFound = true;
        }
    }

    if(!bFound) return -1;
    else if(!rFound)
    {
        ans = 1;
        return 0;
    }
    else return 1;
}
void dfs(int cnt)
{
    int result = isFinish();
    
    if(ans == 1) return;
    if(result <= 0) return;

    // 일단 10번 이동하면 끝
    if(cnt == 10) return;

    char newBoard[11][11];
    memcpy(newBoard, board, sizeof(newBoard)); // 원본 저장
    moveUp();
    // cout << "상";
    // printBoard();
    dfs(cnt+1);

    memcpy(board, newBoard, sizeof(board)); // 원상 복구
    moveDown();
    // cout << "하";
    // printBoard();
    dfs(cnt+1);

    memcpy(board, newBoard, sizeof(board)); // 원상 복구
    moveLeft();
    // cout << "좌";
    // printBoard();
    dfs(cnt+1);

    memcpy(board, newBoard, sizeof(board)); // 원상 복구
    moveRight();
    // cout << "우";
    // printBoard();
    dfs(cnt+1);
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

    dfs(0);

    cout << ans << "\n";

    return 0;
}
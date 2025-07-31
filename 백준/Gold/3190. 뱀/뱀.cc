#include <bits/stdc++.h>

using namespace std;

int n, k, l;

// 상 좌 하 우
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

bool board[101][101]; // 뱀 몸이면 1, 빈 곳이면 0
bool isApple[101][101];

queue<pair<int, char>> dirQ;

int BFS()
{
    int curX = 1, curY = 1;

    queue<pair<int, int>> tailQ; // 꼬리 저장
    tailQ.push({curX, curY});
    board[curX][curY] = 1;

    int t = 0;
    int dir = 3; // 현재 방향 (오른쪽부터 시작)
    
    while(true)
    {
        int nX = curX + dx[dir];
        int nY = curY + dy[dir];

        // 벽이면 끝
        if(nX < 1 || nX > n || nY < 1 || nY > n) break;

        // 뱀이면 끝
        if(board[nX][nY] == 1) break;

        // 사과 있으면 사과 없어짐
        if(isApple[nX][nY]) isApple[nX][nY] = false; 

        // 사과가 없으면 꼬리 이동
        else
        {
            auto [tailX, tailY] = tailQ.front();
            board[tailX][tailY] = 0;
            tailQ.pop();
        }

        
        board[nX][nY] = 1;
        tailQ.push({nX, nY});

        t++;

        auto [sec, nxtDir] = dirQ.front();

        // 방향 바꿀 때
        if(sec == t)
        {
            if(nxtDir == 'L')
            {
                dir++;
                if(dir == 4) dir = 0;
            }
            else
            {
                dir--;
                if(dir == -1) dir = 3;
            }

            dirQ.pop();
        }

        curX = nX;
        curY = nY;
    }

    return t + 1;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for(int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;

        isApple[x][y] = true;
    }

    cin >> l;

    for(int i = 0; i < l; i++)
    {
        int t;
        char dir;

        cin >> t >> dir;

        dirQ.push({t, dir});
    }

    cout << BFS() << "\n";

    return 0;
}
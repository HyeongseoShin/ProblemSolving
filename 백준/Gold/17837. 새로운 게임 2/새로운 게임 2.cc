#include <bits/stdc++.h>

using namespace std;

int n, k;

// 0: 흰색. 1: 빨강, 2: 파랑
int board[15][15];

vector<int> playerStatus[15][15];

int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, 1, -1, 0, 0};

int pX[15];
int pY[15];
int pDir[15];

bool isFinished = false;

void Move(int idx)
{
    int curX = pX[idx];
    int curY = pY[idx];
    int curDir = pDir[idx];

    int nX = curX + dx[curDir];
    int nY = curY + dy[curDir];

    // 벗어나거나 파랑
    if(nX < 1 || nX > n || nY < 1 || nY > n || board[nX][nY] == 2)
    {
        // 이동 방향 변경
        if(curDir % 2 == 1) curDir++;
        else curDir--;

        pDir[idx] = curDir;

        // 새로운 방향
        nX = curX + dx[curDir];
        nY = curY + dy[curDir];
    }


    if(nX >= 1 && nX <= n && nY >= 1 && nY <= n && board[nX][nY] != 2)
    {
        int pos = find(playerStatus[curX][curY].begin(), playerStatus[curX][curY].end(), idx) - playerStatus[curX][curY].begin();

        // 흰색 일 때
        if(board[nX][nY] == 0)
        {
            for(int i = pos; i < (int)playerStatus[curX][curY].size(); i++)
            {
                int curNum = playerStatus[curX][curY][i];

                pX[curNum] = nX;
                pY[curNum] = nY;

                playerStatus[nX][nY].push_back(curNum);
            }
        }
        
        
        // 빨간색일 때
        // 마지막 테케 틀린 이유
        // 이동하는 칸이 빨간색이면 원래 말 순서는 유지되고 새롭게 들어갈 말만 반대로 들어감
        else if(board[nX][nY] == 1)
        {
            for(int i = (int)playerStatus[curX][curY].size() - 1; i >= pos; i--)
            {
                int curNum = playerStatus[curX][curY][i];

                pX[curNum] = nX;
                pY[curNum] = nY;

                playerStatus[nX][nY].push_back(curNum);
            }
        }

        int en = playerStatus[curX][curY].size();

        // 기존 칸 지우기
        for(int i = pos; i < en; i++)
        {
            playerStatus[curX][curY].pop_back();
        }

        if(playerStatus[nX][nY].size() >= 4) isFinished = true;
    }
}



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> board[i][j];
        }
    }

    for(int i = 1; i <= k; i++)
    {
        int x, y, dir;

        cin >> x >> y >> dir;

        // 해당 좌표에 현재 플레이어 추가
        playerStatus[x][y].push_back(i);

        pX[i] = x;
        pY[i] = y;
        pDir[i] = dir;
    }

    int cnt = 1;
    while(cnt <= 1000)
    {
        for(int i = 1; i <= k; i++)
        {
            Move(i);
        }

        if(isFinished) break;
        cnt++;
    }
    
    if(cnt > 1000) cout << "-1\n";
    else cout << cnt << "\n";

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int n;

int board[21][21];

bool isMerged[21][21]; // 이미 합쳐진 블록인가?

int ans = 0; // 정답

void printBoard()
{
    cout << "\n===================\n";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "===================\n";
}

void up()
{
    memset(isMerged, false, sizeof(isMerged));
    for(int i = 0; i < n; i++)
    {
        for(int j = 1; j < n; j++)
        {
            // cout << "j: " << j << " i: " << i << "\n";
            // 빈 칸이면 패스
            if(board[j][i] == 0) continue;

            int num = board[j][i];
            board[j][i] = 0; // 현재 칸 비우기

            int idx = j-1;

            // 빈 칸이면 계속 이동
            while(board[idx][i] == 0 && idx >= 1) idx--;

            // 같은 숫자이고 아직 합쳐지지 않았으면
            if(board[idx][i] == num && !isMerged[idx][i])
            {
                board[idx][i] *= 2;
                ans = max(ans, board[idx][i]);
                isMerged[idx][i] = true;
            }

            // 해당 칸이 빈 칸이면 바로 삽입
            else if(board[idx][i] == 0) board[idx][i] = num;

            // 다른 숫자이면 해당 칸 한 칸 아래에 위치
            else board[idx+1][i] = num;
        }
    }
}

void down()
{
    memset(isMerged, false, sizeof(isMerged));
    for(int i = 0; i < n; i++)
    {
        for(int j = n-2; j >= 0; j--)
        {
            // cout << "j: " << j << " i: " << i << "\n";
            // 빈 칸이면 패스
            if(board[j][i] == 0) continue;

            int num = board[j][i];
            board[j][i] = 0; // 현재 칸 비우기

            int idx = j+1;
            while(board[idx][i] == 0 && idx <= n-2) idx++;

            // 같은 숫자이고 아직 합쳐지지 않았으면
            if(board[idx][i] == num && !isMerged[idx][i])
            {
                
                board[idx][i] *= 2;
                ans = max(ans, board[idx][i]);
                isMerged[idx][i] = true;
            }

            // 해당 칸이 빈 칸이면 바로 삽입
            else if(board[idx][i] == 0) board[idx][i] = num;

            // 다른 숫자이면 해당 칸 한 칸 위에 위치
            else board[idx-1][i] = num;
        }
    }
}

void left()
{
    memset(isMerged, false, sizeof(isMerged));
    for(int i = 0; i < n; i++)
    {
        for(int j = 1; j < n; j++)
        {
            // cout << "j: " << j << " i: " << i << "\n";
            // 빈 칸이면 패스
            if(board[i][j] == 0) continue;

            int num = board[i][j];
            board[i][j] = 0; // 현재 칸 비우기

            int idx = j-1;
            while(board[i][idx] == 0 && idx >= 1) idx--;

            // 같은 숫자이고 아직 합쳐지지 않았으면
            if(board[i][idx] == num && !isMerged[i][idx])
            {  
                board[i][idx] *= 2;
                ans = max(ans, board[i][idx]);
                isMerged[i][idx] = true;  
            }

            // 해당 칸이 빈 칸이면 바로 삽입
            else if(board[i][idx] == 0) board[i][idx] = num;

            // 다른 숫자이면 해당 칸 한 칸 아래에 위치
            else board[i][idx+1] = num;
        }
    }
}

void right()
{
    memset(isMerged, false, sizeof(isMerged));
    for(int i = 0; i < n; i++)
    {
        for(int j = n-2; j >= 0; j--)
        {
            // cout << "j: " << j << " i: " << i << "\n";
            // 빈 칸이면 패스
            if(board[i][j] == 0) continue;

            int num = board[i][j];
            board[i][j] = 0; // 현재 칸 비우기

            int idx = j+1;
            while(board[i][idx] == 0 && idx <= n-2) idx++;

            // 같은 숫자이고 아직 합쳐지지 않았으면
            if(board[i][idx] == num && !isMerged[i][idx])
            {
                board[i][idx] *= 2;
                ans = max(ans, board[i][idx]);
                isMerged[i][idx] = true;   
            }

            // 해당 칸이 빈 칸이면 바로 삽입
            else if(board[i][idx] == 0) board[i][idx] = num;

            // 다른 숫자이면 해당 칸 한 칸 위에 위치
            else board[i][idx-1] = num;
        }
    }
}

void getAns(int cnt)
{
    // 5번 이동했으면 끝
    if(cnt == 5) return;
    
    int tmp[21][21];
    memcpy(tmp, board, sizeof(board));

    // 상, 하, 좌, 우 이동
    up();
    // printBoard();
    getAns(cnt+1);
    memcpy(board, tmp, sizeof(tmp)); // 원상 복구

    down();
    // printBoard();
    getAns(cnt+1);
    memcpy(board, tmp, sizeof(tmp)); // 원상 복구

    left();
    // printBoard();
    getAns(cnt+1);
    memcpy(board, tmp, sizeof(tmp)); // 원상 복구

    right();
    // printBoard();
    getAns(cnt+1);
    memcpy(board, tmp, sizeof(tmp)); // 원상 복구   
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> board[i][j];
            ans = max(ans, board[i][j]);
        }
    }

    getAns(0);

    cout << ans << "\n";

    return 0;
}
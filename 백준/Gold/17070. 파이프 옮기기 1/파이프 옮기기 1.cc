#include <bits/stdc++.h>

using namespace std;

int n;

int arr[20][20];

// board[i][j][0]: 파이프 끝 (i,j)에 가로로 오는 경우
// board[i][j][1]: 파이프 끝 (i,j)에 세로로 오는 경우
// board[i][j][2]: 파이프 끝 (i,j)에 대각선으로 오는 경우

int board[20][20][3];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    // (0,0), (0,1)에 가로로 파이프가 설치되어 있음
    // board[0][1][0] = 1;

    for(int i = 0; i < n; i++)
    {
        if(arr[0][i] != 0) break;
        board[0][i][0] = 1;

    }

    for(int i = 1; i < n; i++)
    {
        // 파이프가 우, 하 방향으로 이동하기 때문에 초기 파이프가 위치한 y값 보다 작은 좌표는 쓰이지 않음
        for(int j = 2; j < n; j++)
        {
            if(arr[i][j] != 0)
            {
                continue;
            }

            

            if(arr[i][j-1] == 0 && arr[i-1][j] == 0)
            {
                // 현재 대각선이 되어있으려면 이전에 가로 or 세로 or 대각선이어야함
                board[i][j][2] = board[i-1][j-1][0] + board[i-1][j-1][1] + board[i-1][j-1][2];
            }

            if(arr[i][j-1] == 0)
            {
                // 현재 가로가 되어있으려면 이전에 가로 or 대각선이어야함
                board[i][j][0] = board[i][j-1][0] + board[i][j-1][2]; // 가로인 경우
            }

            if(arr[i-1][j] == 0)
            {
                // 현재 세로가 되어있으려면 이전에 세로 or 대각선이어야함
                board[i][j][1] = board[i-1][j][1] + board[i-1][j][2]; // 세로인 경우
            }
        }
    }
    
    cout << board[n-1][n-1][0] + board[n-1][n-1][1] + board[n-1][n-1][2] << "\n";    

    return 0;
}
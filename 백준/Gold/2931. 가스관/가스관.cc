#include <bits/stdc++.h>
using namespace std;

int r, c;
char board[27][27]; // 1-based로 처리, 안전하게 0~26 사용

// 끊긴 부분 찾기
void findEmpty()
{
    for(int i = 1; i <= r; i++)
    {
        for(int j = 1; j <= c; j++)
        {
            if(board[i][j] != '.') continue;

            // 주변 파이프 존재 여부 확인
            bool isUp = (board[i-1][j] == '|' || board[i-1][j] == '+' || board[i-1][j] == '1' || board[i-1][j] == '4');
            bool isDown = (board[i+1][j] == '|' || board[i+1][j] == '+' || board[i+1][j] == '2' || board[i+1][j] == '3');
            bool isLeft = (board[i][j-1] == '-' || board[i][j-1] == '+' || board[i][j-1] == '1' || board[i][j-1] == '2');
            bool isRight = (board[i][j+1] == '-' || board[i][j+1] == '+' || board[i][j+1] == '3' || board[i][j+1] == '4');

            char ansShape = '?';

            if(isUp && isDown && isLeft && isRight) ansShape = '+';
            else if(isUp && isDown) ansShape = '|';
            else if(isLeft && isRight) ansShape = '-';
            else if(isDown && isRight) ansShape = '1';
            else if(isUp && isRight) ansShape = '2';
            else if(isUp && isLeft) ansShape = '3';
            else if(isDown && isLeft) ansShape = '4';

            if(ansShape != '?')
            {
                cout << i << " " << j << " " << ansShape << "\n";
                return;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c;
    for(int i = 1; i <= r; i++)
    {
        string s;
        cin >> s;
        for(int j = 1; j <= c; j++)
            board[i][j] = s[j-1]; // 1-based로 저장
    }

    findEmpty();

    return 0;
}

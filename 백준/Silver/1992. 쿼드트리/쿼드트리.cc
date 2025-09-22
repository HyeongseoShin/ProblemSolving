#include <bits/stdc++.h>

using namespace std;

int n;

int board[65][65];

// 해당 칸이 모두 0이거나 1인지 확인
int check(int stX, int stY, int enX, int enY)
{
    for(int i = stX; i < enX; i++)
    {
        for(int j = stY; j < enY; j++)
        {
            if(board[stX][stY] != board[i][j]) return -1;
        }
    }

    return board[stX][stY];
}

void quadTree(int stX, int stY, int enX, int enY)
{
    int val = check(stX, stY, enX, enY);

    if(val >= 0)
    {
        cout << val;
        return;
    }

    int midX = (stX + enX) / 2; // 무한 루프 원인 => 원래 enX / 2
    int midY = (stY + enY) / 2; // 무한 루프 원인 => 원래 enY / 2
    
    cout << "(";

    quadTree(stX, stY, midX, midY); // 좌상
    quadTree(stX, midY, midX, enY);// 우상
    quadTree(midX, stY, enX, midY); // 좌하
    quadTree(midX, midY, enX, enY);// 우하

    cout << ")";   
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        for(int j = 0; j < n; j++)
        {
            board[i][j] = s[j] - '0';
        }
    }

    quadTree(0, 0, n, n);

    cout << "\n";
    
    return 0;
}
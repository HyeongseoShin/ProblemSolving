// https://www.acmicpc.net/problem/1022

#include <bits/stdc++.h>

using namespace std;

int r1, c1, r2, c2;

// 정답 배열 크기 : (|r2 - r1| + 1) * (|c2 - c1| + 1)
// 최대 수 : (|r2 - r1| + 1) * (|c2 - c1| + 1)

int board[50][50];

int rSz, cSz;

int maxLen = -1;

int getNumLen(int num)
{
    int len = 0;

    while(num > 0)
    {
        num /= 10;
        len++;
    }

    return len;
}

// 좌표를 보고 현재 위치의 값을 구해서 리턴함
int getCurVal(int x, int y)
{
    // 현재 (x, y)가 어느 구간에 있는지 구하기
    int pos = max(abs(x), abs(y));

    // (x, y)는 (minX, minY) ~ (maxX, maxX) 사이에 위치 하고 있음
    int minX = pos * -1;
    int minY = pos * -1; // 실질적으로 좌상단 좌표는 좌측으로 한 칸 더 간 좌표임
    
    int maxX = pos;
    int maxY = pos;

    int minVal = 0, maxVal = 0, tmpVal = 0;

    minVal = (maxX * 2 - 1) * (maxX * 2 - 1);
    tmpVal = (maxX * 2) * (maxX * 2);
    maxVal = (maxX * 2 + 1) * (maxX * 2 + 1);

    tmpVal++;
    
    

    // 이전인 경우
    // y == maxY && x != maxX or
    // x == minX
    
    // 이후인 경우
    // y == minY
    // x == maxX

    int ret = 0;
    int val = abs(minX - x) + abs(minY - y);

    // 이전인 경우
    if((y == maxY && x != maxX) || x == minX) ret = tmpVal - val;
    else if(y == minY || x == maxX) ret = tmpVal + val;

    // cout << "(" << x << " " << y << ")는 (" << minX << " " << minY << ") ~ (" << maxX << " " << maxY << ")사이에 있고 " << minVal << " ~ " << maxVal << " 사잇값임 리턴 값: " << ret << "\n";

    return ret;
    
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r1 >> c1 >> r2 >> c2;

    rSz = abs(r2 - r1) + 1;
    cSz = abs(c2 - c1) + 1;


    // 일단 각 칸에 해당 하는 값을 board에 저장
    for(int i = 0; i < rSz; i++)
    {
        for(int j = 0; j < cSz; j++)
        {
            board[i][j] = getCurVal(r1 + i, c1 + j);
            maxLen = max(maxLen, getNumLen(board[i][j]));
        }
    }

    for(int i = 0; i < rSz; i++)
    {
        for(int j = 0; j < cSz; j++)
        {
            int curLen = getNumLen(board[i][j]);

            for(int k = curLen; k < maxLen; k++)
            {
                cout << " ";
            }
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }


    return 0;
}
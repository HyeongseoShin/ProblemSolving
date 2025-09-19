#include <bits/stdc++.h>

using namespace std;

// 경로 정보
int route[4][30] = {
    {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, },
    {10, 13, 16, 19, 25, 30, 35, 40, },
    {20, 22, 24, 25, 30, 35, 40, },
    {30, 28, 27, 26, 25, 30, 35, 40, }
};

// 각 경로의 길이 정보 추가
int pathLen[] = {21, 8, 7, 8};

// 주사위 정보
int dice[10];

// 각 위치에 플레이어 있는지 확인
bool isPlayer[4][30];

int ans = 0;

// 현재 플레이어 위치
pair<int, int> players[4];

// 이동하려는 칸이 이동할 수 있는지 확인
bool checkCanGo(int nX, int nY)
{
    // 도착지점이면 가능
    if((nX == 0 && nY >= pathLen[0]) || (nX == 1 && nY >= pathLen[1]) || (nX == 2 && nY >= pathLen[2]) || (nX == 3 && nY >= pathLen[3]))
    {
        return true;
    }

    int val = route[nX][nY];

    // 40 지점: 모든 경로의 40 좌표를 확인
    if (val == 40)
    {
        return !(isPlayer[0][20] || isPlayer[1][7] || isPlayer[2][6] || isPlayer[3][7]);
    }

    // 25 지점: 25가 있는 모든 좌표를 확인
    if (val == 25)
    {
        return !(isPlayer[1][4] || isPlayer[2][3] || isPlayer[3][4]);
    }

    // 35 지점: 35가 있는 모든 좌표를 확인
    if (val == 35)
    {
        return !(isPlayer[1][6] || isPlayer[2][5] || isPlayer[3][6]);
    }

    // 중앙 30 지점 (30->28 경로의 시작점 30과 구분해야 함)
    if (val == 30 && ((nX == 1 && nY == 5) || (nX == 2 && nY == 4) || (nX == 3 && nY == 5))) {
         return !(isPlayer[1][5] || isPlayer[2][4] || isPlayer[3][5]);
    }

    return !isPlayer[nX][nY];
}

// <주사위 순서, 플레이어 위치, 현재 점수>
void GetAns(int idx, int score)
{
    // 주사위 10번 다 던졌으면 끝
    if(idx == 10)
    {
        ans = max(ans, score);
        return;
    }

    for(int i = 0; i < 4; i++)
    {
        // 현재 말의 위치
        auto[curX, curY] = players[i];

        // 이미 도착한 말이면 패스
        if(curX == -1) continue;

        // 현재 주사위를 반영한 다음 위치
        int nX = curX;
        int nY = curY + dice[idx];

        bool isArrived = false;

        if((nX == 0 && nY >= pathLen[0]) || (nX == 1 && nY >= pathLen[1]) || (nX == 2 && nY >= pathLen[2]) || (nX == 3 && nY >= pathLen[3]))
        {
            isArrived = true;
        }

        // 도착한 말이 아닐 때만 검사
        // 꺾이는 부분 10, 20, 30에 도착했는지 확인하기
        if(!isArrived && nX == 0)
        {
            if(route[nX][nY] == 10) {nX = 1, nY = 0; }
            else if(route[nX][nY] == 20) {nX = 2, nY = 0; }
            else if(route[nX][nY] == 30) {nX = 3, nY = 0; }
        }

        // 현재 말을 다음 위치로 움직일 수 있으면
        if(checkCanGo(nX, nY))
        { 
            isPlayer[curX][curY] = false;

            if(isArrived)
            {
                players[i] = {-1, -1}; // 도착 상태로 변경
                GetAns(idx + 1, score);
            }

            else
            {
                players[i] = {nX, nY};
                isPlayer[nX][nY] = true;
                GetAns(idx + 1, score + route[nX][nY]);
                isPlayer[nX][nY] = false;
            }
            
            isPlayer[curX][curY] = true;
            players[i] = {curX, curY};
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // 주사위 입력 받음
    for(int i = 0; i < 10; i++)
    {
        cin >> dice[i];
    }

    GetAns(0, 0);

    cout << ans << "\n";

    return 0;
}
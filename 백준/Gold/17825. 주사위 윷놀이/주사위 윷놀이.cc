#include <bits/stdc++.h>

using namespace std;

// 경로 정보 (기존과 동일)
int route[4][30] = {
    {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40},
    {10, 13, 16, 19, 25, 30, 35, 40},
    {20, 22, 24, 25, 30, 35, 40},
    {30, 28, 27, 26, 25, 30, 35, 40}
};

// 각 경로의 길이 정보 추가
int path_len[] = {21, 8, 7, 8};

// 주사위 정보 (기존과 동일)
int dice[10];

// 각 위치에 플레이어 있는지 확인 (기존과 동일)
bool isPlayer[4][30];

int ans = 0;

// 현재 플레이어 위치 (기존과 동일)
pair<int, int> players[4];

// 💡 [수정된 부분 1] 공통 지점을 고려하는 checkCanGo 함수
bool checkCanGo(int nX, int nY)
{
    // 도착 지점(경로 길이 초과)은 항상 이동 가능
    if ((nX == 0 && nY >= path_len[0]) || (nX == 1 && nY >= path_len[1]) ||
        (nX == 2 && nY >= path_len[2]) || (nX == 3 && nY >= path_len[3])) {
        return true;
    }

    int val = route[nX][nY];

    // 40 지점: 모든 경로의 40 좌표를 확인
    if (val == 40) {
        return !(isPlayer[0][20] || isPlayer[1][7] || isPlayer[2][6] || isPlayer[3][7]);
    }
    // 25 지점: 25가 있는 모든 좌표를 확인
    if (val == 25) {
        return !(isPlayer[1][4] || isPlayer[2][3] || isPlayer[3][4]);
    }
    // 35 지점: 35가 있는 모든 좌표를 확인
    if (val == 35) {
        return !(isPlayer[1][6] || isPlayer[2][5] || isPlayer[3][6]);
    }
    // 중앙 30 지점 (30->28 경로의 시작점 30과 구분해야 함)
    if (val == 30 && ((nX == 1 && nY == 5) || (nX == 2 && nY == 4) || (nX == 3 && nY == 5))) {
         return !(isPlayer[1][5] || isPlayer[2][4] || isPlayer[3][5]);
    }

    // 그 외 모든 고유한 지점은 해당 좌표만 확인
    return !isPlayer[nX][nY];
}

// 💡 [수정된 부분 2] 도착 처리 로직을 개선한 GetAns 함수
void GetAns(int idx, int score)
{
    if (idx == 10) {
        ans = max(ans, score);
        return;
    }

    for (int i = 0; i < 4; i++) {
        auto [curX, curY] = players[i];

        // 이미 도착한 말은 curX를 -1로 표시하여 건너뜀
        if (curX == -1) continue;

        int nX = curX;
        int nY = curY + dice[idx];

        // 경로 길이를 이용해 도착 여부 명시적 확인
        bool isArrived = false;
        if ((nX == 0 && nY >= path_len[0]) || (nX == 1 && nY >= path_len[1]) ||
            (nX == 2 && nY >= path_len[2]) || (nX == 3 && nY >= path_len[3])) {
            isArrived = true;
        }

        // 파란색 칸 경로 변경 (도착한 말이 아닐 경우에만)
        if (!isArrived) {
            if (nX == 0 && route[nX][nY] == 10) { nX = 1; nY = 0; }
            else if (nX == 0 && route[nX][nY] == 20) { nX = 2; nY = 0; }
            else if (nX == 0 && route[nX][nY] == 30) { nX = 3; nY = 0; }
        }

        if (checkCanGo(nX, nY)) {
            // 현재 위치 비우기
            isPlayer[curX][curY] = false;

            if (isArrived) {
                players[i] = {-1, -1}; // 도착 상태로 변경
                GetAns(idx + 1, score); // 도착 시 점수 추가 없음
            } else {
                players[i] = {nX, nY};
                isPlayer[nX][nY] = true;
                GetAns(idx + 1, score + route[nX][nY]);
                isPlayer[nX][nY] = false;
            }

            // Backtracking (원상 복구)
            players[i] = {curX, curY};
            isPlayer[curX][curY] = true;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 10; i++) {
        cin >> dice[i];
    }
    
    // players 배열은 전역 변수라 {0, 0}으로 자동 초기화됨
    
    // 💡 [수정된 부분 3] 불필요한 초기화 코드 제거 및 함수 호출 방식 변경
    GetAns(0, 0);

    cout << ans << "\n";

    return 0;
}
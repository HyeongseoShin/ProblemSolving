/*
완전 탐색
궁수 3명이 위치할 수 있는 모든 위치에 대해 적 사살 수 구하고 그 중 최댓값이 정답
*/
#include <bits/stdc++.h>

using namespace std;

int n, m, d;
int grid[20][20];
int copiedGrid[20][20];
int ans = 0;


// 매회차마다 배열 복사
void CopyGrid()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            copiedGrid[i][j] = grid[i][j];
        }
    }
}

int GetDist(int r1, int c1, int r2, int c2)
{
    return abs(r1 - r2) + abs(c1 - c2);
}

// 가장 가까운 적 중 가장 왼쩍에 있는 적 좌표 구하기
pair<int, int> GetTargetPos(int r, int c)
{
    int curDist = 1000;
    pair<int, int> pos = {-1, -1};

    for(int i = 0; i < m; i++)
    {
        for(int j = r - 1; j >= 0; j--)
        {
            if(GetDist(j, i, r, c) <= d && curDist > GetDist(j, i, r, c) && copiedGrid[j][i] == 1)
            {
                curDist = GetDist(j, i, r, c);
                pos = {j, i};
            }
        }
    }

    // cout << "(x, y): " << pos.first << " " << pos.second << " (r, c): " << r << " " << c << "\n";

    return pos;
}

// 각 궁수의 위치 열
int GetKilledEnemy(vector<int> archers)
{
    int result = 0; // 현재 죽은 적의 수
    CopyGrid(); // 배열 초기화
    int curPos = n; // 궁수 위치 행 초기화
    vector<pair<int, int>> target;

    // 궁수의 위치가 0행보다 클 때까지만 실행
    while(curPos > 0)
    {
        target.clear();
        // 각 궁수의 타겟 좌표 구하기
        for(int i = 0; i < 3; i++)
        {
            pair<int, int> res = GetTargetPos(curPos, archers[i]);
            if(res.first != -1 && res.second != -1 && find(target.begin(), target.end(), res) == target.end())
            {
                target.push_back(res);
            }
            
        }

        result += target.size();

        // cout << "result: " << result << "\n";

        for(int i = 0; i < (int)target.size(); i++)
        {
            int x = target[i].first;
            int y = target[i].second;

            copiedGrid[x][y] = 0;
        }
        curPos--;
    }

    return result;

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> d;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    // 위치 가능한 모든 경우의 수에서 시뮬레이션 실행
    vector<int> archers(3);
    for(int k = 0; k < m; k++)
    {
        for(int i = k + 1; i < m; i++)
        {
            for(int j = i + 1; j < m; j++)
            {
                archers[0] = k;
                archers[1] = i;
                archers[2] = j;

                ans = max(ans, GetKilledEnemy(archers));

                // cout << "ans: " << ans << " " << k << " " << i << " " << j << "\n";
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
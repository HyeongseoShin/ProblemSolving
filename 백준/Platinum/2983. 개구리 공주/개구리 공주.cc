#include <bits/stdc++.h>

using namespace std;

int n, k;

string dir;

// A, D 방향은 (curX - curY) == (nX - nY)가 같으면 됨
// B, C 방향은 (curX + curY) == (nX + nY)가 같으면 됨
// 가까운 순이므로 set을 사용해 자동 정렬되도독

set<tuple<int, int, int>> adDir;
set<tuple<int, int, int>> bcDir;

// 현재 좌표
int curX, curY;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    cin >> dir;

    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;

        if(i == 0)
        {
            curX = x;
            curY = y;
        }
        adDir.insert({x - y, x, y});
        bcDir.insert({x + y, x, y});
    }

    for(int i = 0; i < k; i++)
    {
        if(dir[i] == 'A')
        {
            // 현재 좌표 위치 찾기
            auto it = adDir.find({curX - curY, curX, curY});

            // 현재 좌표가 마지막 좌표이면 현재 방향에서 갈 수 있는 곳이 없음
            if(it == prev(adDir.end())) continue;

            // 현재 좌표에서 주어진 방향으로 갔을 때 가장 가까운 좌표는
            // 현재 좌표 바로 다음 좌표
            auto [nVal, nX, nY] = *next(it);

            // 바로 다음 좌표를 확인했는데 증감값이 다름 ==> 진행 방향에 있는 좌표가 아님
            if(nVal != (curX - curY)) continue;

            // 현재 위치에 있는 식물 삭제
            adDir.erase(it);
            bcDir.erase({curX + curY, curX, curY});

            curX = nX;
            curY = nY;
        }

        else if(dir[i] == 'B')
        {
            // 현재 좌표 위치 찾기
            auto it = bcDir.find({curX + curY, curX, curY});

            // 현재 좌표가 마지막 좌표이면 현재 방향에서 갈 수 있는 곳이 없음
            if(it == prev(bcDir.end())) continue;

            // 현재 좌표에서 주어진 방향으로 갔을 때 가장 가까운 좌표는
            // 현재 좌표 바로 다음 좌표
            auto [nVal, nX, nY] = *next(it);

            // 바로 다음 좌표를 확인했는데 증감값이 다름 ==> 진행 방향에 있는 좌표가 아님
            if(nVal != (curX + curY)) continue;

            // 현재 위치에 있는 식물 삭제
            adDir.erase({curX - curY, curX, curY});
            bcDir.erase(it);

            curX = nX;
            curY = nY;
        }

        else if(dir[i] == 'C')
        {
            // 현재 좌표 위치 찾기
            auto it = bcDir.find({curX + curY, curX, curY});

            // 현재 좌표가 처음 좌표이면 현재 방향에서 갈 수 있는 곳이 없음
            if(it == bcDir.begin()) continue;

            // 현재 좌표에서 주어진 방향으로 갔을 때 가장 가까운 좌표는
            // 현재 좌표 바로 전 좌표
            auto [nVal, nX, nY] = *prev(it);

            // 바로 다음 좌표를 확인했는데 증감값이 다름 ==> 진행 방향에 있는 좌표가 아님
            if(nVal != (curX + curY)) continue;

            // 현재 위치에 있는 식물 삭제
            adDir.erase({curX - curY, curX, curY});
            bcDir.erase(it);

            curX = nX;
            curY = nY;
        }

        else if(dir[i] == 'D')
        {
            // 현재 좌표 위치 찾기
            auto it = adDir.find({curX - curY, curX, curY});

            // 현재 좌표가 처음 좌표이면 현재 방향에서 갈 수 있는 곳이 없음
            if(it == adDir.begin()) continue;

            // 현재 좌표에서 주어진 방향으로 갔을 때 가장 가까운 좌표는
            // 현재 좌표 바로 전 좌표
            auto [nVal, nX, nY] = *prev(it);

            // 바로 다음 좌표를 확인했는데 증감값이 다름 ==> 진행 방향에 있는 좌표가 아님
            if(nVal != (curX - curY)) continue;

            // 현재 위치에 있는 식물 삭제
            adDir.erase(it);
            bcDir.erase({curX + curY, curX, curY});

            curX = nX;
            curY = nY;
        }
    }

    cout << curX << " " << curY << "\n";

    


    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int t, n;

int stX, stY; // 시작 위치
int goalX, goalY; // 도착 위치

pair<int ,int> store[101]; // 편의점 좌표

// 두 점 사이의 거리가 맥주 20개로 갈 수 있는 거리인지 아닌지 판단
bool isReachable(int x1, int y1, int x2, int y2)
{
    if(abs(x1 - x2) + abs(y1 - y2) <= 20 * 50) return true;
    else return false;
}

void BFS()
{
    bool vis[101]; // 편의점 방문 표시
    memset(vis, false, sizeof(vis));

    queue<pair<int, int>> q;
    q.push({stX, stY});

    while(!q.empty())
    {
        auto [curX, curY] = q.front();
        q.pop();

        // 현재 위치에서 도착점 갈 수 있으면 끝
        if(isReachable(curX, curY, goalX, goalY))
        {
            cout << "happy\n";
            return;
        }

        for(int i = 0; i < n; i++)
        {
            auto [sX, sY] = store[i];

            if(vis[i]) continue;

            if(isReachable(curX, curY, sX, sY))
            {
                q.push({sX, sY});
                vis[i] = true;
            }
        }
    }

    cout << "sad\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;
        cin >> stX >> stY;

        // 편의점 위치 입력
        for(int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            store[i] = {x, y};
        }

        cin >> goalX >> goalY;

        BFS();
    }

    return 0;
}
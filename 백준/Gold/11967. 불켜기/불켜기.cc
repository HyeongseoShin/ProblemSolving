#include <bits/stdc++.h>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int n, m;

// 각 방 별 불 켤 수 있는 스위치 목록
// 1-indexed
vector<pair<int, int>> switches[103][103];
bool vis[103][103]; // 방문 확인 배열

// 각 방 별 불 켜져 있는지 => 불 켜진 곳만 이동 가능
// 1-indexed
bool isLightOn[103][103];

int turnLight()
{
    queue<pair<int, int>> q;
    queue<pair<int, int>> waitingQ; // 불 켜져 있지만 아직 방문 안 한 칸

    q.push({1, 1});

    isLightOn[1][1] = true;
    vis[1][1] = true;
    int cnt = 1;

    while(!q.empty())
    {
        auto [curX, curY] = q.front();
        q.pop();

        // 불 켜기
        for(int i = 0; i < (int)switches[curX][curY].size(); i++)
        {
            auto [nX, nY] = switches[curX][curY][i];

            // 전에 방문했던 적이 있다면 방문 후보에 추가 X
            if(isLightOn[nX][nY]) continue;
            
            isLightOn[nX][nY] = true;
            cnt++;

            // 방문 후보에 추가
            waitingQ.push({nX, nY});
        }

        int sz = waitingQ.size();
        while(sz--)
        {
            auto [x, y] = waitingQ.front();
            waitingQ.pop();

            for(int i = 0; i < 4; i++)
            {
                int nX = x + dx[i];
                int nY = y + dy[i];

                if(nX < 1 || nX > n || nY < 1 || nY > n) continue; // 범위 벗어나면 패스
                if(isLightOn[nX][nY] && vis[nX][nY]) // 주위에 불 켜져 있고 방문한 곳 있으면 현재 위치에서 방문 가능
                {
                    q.push({x, y});
                    vis[x][y] = true;
                    break;
                }
            }

            // 이번에 방문 못하게 되면 다시 후보에 넣기
            if(!vis[x][y]) waitingQ.push({x, y});
        }
    }

    return cnt;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        int x, y, a, b;
        cin >> x >> y >> a >> b;

        switches[x][y].push_back({a, b});
    }

    cout << turnLight() << "\n";

    return 0;
}
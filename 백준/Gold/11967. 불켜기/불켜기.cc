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

    q.push({1, 1});

    isLightOn[1][1] = true;
    vis[1][1] = true;
    int cnt = 1;

    while(!q.empty())
    {
        auto [curX, curY] = q.front();
        q.pop();

        // 불 켜기
        for(auto [nX, nY] : switches[curX][curY])
        {
            // 전에 방문했던 적이 있다면 방문 후보에 추가 X
            if(isLightOn[nX][nY]) continue;
            
            isLightOn[nX][nY] = true;
            cnt++;

            // 현재 불 켠 방이 바로 접근 가능하면 큐에 삽입
            for(int i = 0; i < 4; i++)
            {
                int aX = nX + dx[i];
                int aY = nY + dy[i];

                if(aX < 1 || aX > n || aY < 1 || aY > n) continue; // 범위 벗어나면 패스
                if(isLightOn[aX][aY] && vis[aX][aY]) // 주위에 불 켜져 있고 방문한 곳 있으면 현재 위치에서 방문 가능
                {
                    q.push({nX, nY});
                    vis[nX][nY] = true;
                    break;
                }
            }
        }

        for(int i = 0; i < 4; i++)
        {
            int nX = curX + dx[i];
            int nY = curY + dy[i];

            if(nX < 1 || nX > n || nY < 1 || nY > n) continue;
            if(vis[nX][nY]) continue;
            if(!isLightOn[nX][nY]) continue;
            
            q.push({nX, nY});
            vis[nX][nY] = true;
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
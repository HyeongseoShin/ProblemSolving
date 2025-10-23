#include <bits/stdc++.h>

using namespace std;

int s;

// dist[i][j] : 현재 화면에 i개 나와있고 클립 보드에 j개 있을 때 최단 시간
int dist[1005][1005];

int ans = 0;

bool check(int screen, int clip)
{
    if(screen < 0 || screen >= 1001 || clip < 0 || clip >= 1001) return false;

    return true;
}
void BFS()
{
    queue<pair<int, int>> q;
    q.push({1, 0});

    memset(dist, -1, sizeof(dist));
    dist[1][0] = 0;

    while(!q.empty())
    {
        auto [curScreen, curClip] = q.front();
        q.pop();

        // 이모티콘 개수 채우면 끝
        if(curScreen == s)
        {
            ans = dist[curScreen][curClip];
            return;
        }

        int nScreen, nClip;

        // 현재 화면 클립보드에 저장
        nScreen = curScreen;
        nClip = curScreen;

        if(check(nScreen, nClip) && dist[nScreen][nClip] == -1)
        {
            dist[nScreen][nClip] = dist[curScreen][curClip] + 1;
            q.push({nScreen, nClip});
        }
        
        // 클립 보드에 있는 이모티콘 화면에 붙여넣기
        nScreen = curScreen + curClip;
        nClip = curClip;

        if(check(nScreen, nClip) && dist[nScreen][nClip] == -1)
        {
            dist[nScreen][nClip] = dist[curScreen][curClip] + 1;
            q.push({nScreen, nClip});
        }


        // 화면에 있는 이모티콘 중 하나 삭제
        nScreen = curScreen - 1;
        nClip = curClip;

        if(check(nScreen, nClip) && dist[nScreen][nClip] == -1)
        {
            dist[nScreen][nClip] = dist[curScreen][curClip] + 1;
            q.push({nScreen, nClip});
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;

    BFS();

    cout << ans << "\n";

    return 0;
}
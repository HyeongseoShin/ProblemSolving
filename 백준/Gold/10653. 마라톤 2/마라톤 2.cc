#include <bits/stdc++.h>

using namespace std;

#define INF 1000001

int n, k;

vector<pair<int, int>> pos;

// dp[i][j] : i번 체크포인트까지 왔을 때 j번 스킵했을 때 최소 거리
int dp[505][505];

int dist[505][505];

int ans = INF;

int GetDist(int x1, int y1, int x2, int y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;

        pos.push_back({x, y});
    }

    // 각 점에서 각 점으로 갈 수 있는 거리 계산
    for(int i = 0; i < n; i++)
    {
        auto [curX, curY] = pos[i];
        for(int j = 0; j < n; j++)
        {
            auto [nX, nY] = pos[j];
            dist[i][j] = GetDist(curX, curY, nX, nY);
        }
    }

    // DP 배열 초기화
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= k; j++)
        {
            dp[i][j] = INF;
        }
    }

    // DP 시작점 초기화
    dp[0][0] = 0;

    // DP 실행
    // 체크포인트 순회
    for(int i = 1; i < n; i++)
    {
        // 스킵 횟수 순회
        for(int j = 0; j <= k; j++)
        {
            // 이전까지 스킵한 횟수
            for(int l = 0; l <= k; l++)
            {
                // 현재 좌표까지 j번 스킵했을 때의 최솟값 현재와 비교
                // dp[마지막 방문좌표][현재까지 스킵 횟수 - 마지막 방문까지의 스킵 횟수] + 마지막 방문 좌표 ~ 현재 좌표까지의 거리
                if(i - l - 1 >= 0 && j - l >= 0)
                {
                    dp[i][j] = min(dp[i][j], dp[i - l - 1][j - l] + dist[i - l - 1][i]);
                }
                
            }
        }
    }

    for(int i = 0; i <= k; i++)
    {
        ans = min(ans, dp[n-1][i]);
    }
    
    cout << ans << "\n";

    return 0;
}
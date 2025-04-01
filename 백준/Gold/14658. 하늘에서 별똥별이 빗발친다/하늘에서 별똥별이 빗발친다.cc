#include <bits/stdc++.h>

using namespace std;

int n, m, l, k;

vector<pair<int, int>> starPos;

int ans = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> l >> k;

    for(int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;

        starPos.push_back({x, y});
    }

    for(int i = 0; i < k; i++)
    {
        for(int j = 0; j < k; j++)
        {
            // "두 별의 좌표가 이루는 사각형의 좌상단을 기준으로 트램펄린 설치"
            int curX = starPos[i].first;
            int curY = starPos[j].second;
            
            int cnt = 0;
            for(int a = 0; a < k; a++)
            {
                auto [nX, nY] = starPos[a];

                if(curX <= nX && nX <= curX + l && curY <= nY && nY <= curY + l)
                {
                    cnt++;
                }
            }

            ans = max(ans, cnt);
        }
    }

    cout << k - ans << "\n";

    return 0;
}
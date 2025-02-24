#include <bits/stdc++.h>

using namespace std;

int n, m, l, k; // n: 가로, m: 세로, l: 트램펄린 한 변 길이, k: 별똥별 수

vector<pair<int, int>> starPos;

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

    int ans = 0;
    for(int i = 0; i < k; i++)
    {
        for(int j = 0; j < k; j++)
        {
            int curX = starPos[i].first;
            int curY = starPos[j].second;

            // cout << "(" << starPos[i].first << ", " << starPos[i].second << ") ";
            // cout << "(" << starPos[j].first << ", " << starPos[j].second << ") " << "\n";

            int cnt = 0;
            for(int a = 0; a < k; a++)
            {
                int nX = starPos[a].first;
                int nY = starPos[a].second;

                if(curX <= nX && nX <= curX + l && curY <= nY && nY <= curY + l)
                {
                    cnt++;
                    // cout << "(" << nX << ", " << nY << ")" << "\n";
                }
            }
            ans = max(ans, cnt);
            // cout << "========================\n";
        }
    }

    cout << k - ans << "\n";

    return 0;
}
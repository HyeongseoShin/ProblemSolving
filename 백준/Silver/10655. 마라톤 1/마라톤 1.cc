#include <bits/stdc++.h>

using namespace std;

int n;

pair<int, int> checkPoints[100001];

int ans = INT_MAX;
int sum = 0;

int GetDist(pair<int, int> past, pair<int, int> cur)
{
    auto [x1, y1] = past;
    auto [x2, y2] = cur;

    return abs(x1 - x2) + abs(y1 - y2);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;

        checkPoints[i] = {x, y};

        if(i > 0)
        {
            sum += GetDist(checkPoints[i-1], checkPoints[i]);
        }
    }

    // cout << sum << "\n";

    for(int i = 1; i < n - 1; i++)
    {
        int res = sum - GetDist(checkPoints[i-1], checkPoints[i]) - GetDist(checkPoints[i], checkPoints[i+1]) + GetDist(checkPoints[i-1], checkPoints[i+1]);

        ans = min(ans, res);
    }

    cout << ans << "\n";


    return 0;
}
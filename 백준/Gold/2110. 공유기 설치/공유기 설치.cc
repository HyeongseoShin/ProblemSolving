#include <bits/stdc++.h>

using namespace std;

int n, c;

vector<int> pos;

int getCnt(int x)
{
    int cnt = 1;
    int lastPos = 0;

    for(int i = 1; i < n; i++)
    {
        if(pos[i] - pos[lastPos] >= x)
        {
            cnt++;
            lastPos = i;
        }

        if(cnt == c) break;
    }

    return cnt;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> c;

    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        pos.push_back(x);
    }

    sort(pos.begin(), pos.end());

    int l = 0;
    int r = 1000000001;

    int ans = -1;
    while(l < r)
    {
        int mid = (l + r) / 2;
        int cnt = getCnt(mid);

        // cout << "cnt: " << cnt << " mid: " << mid << "\n";

        if(cnt < c) r = mid;
        else
        {
            ans = max(ans, mid);
            l = mid + 1;
        }
    }

    cout << ans << "\n";

    return 0;
}
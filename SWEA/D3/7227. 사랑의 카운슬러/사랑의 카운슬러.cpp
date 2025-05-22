#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;

ll x[21];
ll y[21];

bool isUsed[21];

ll ans = LLONG_MAX;

ll GetDist(ll x1, ll y1, ll x2, ll y2)
{
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

void GetAns(int idx, ll curX, ll curY, int cnt)
{
    if(cnt == n / 2)
    {
        ll tmpX = 0;
        ll tmpY = 0;

        for(int i = 0; i < n; i++)
        {
            if(isUsed[i]) continue;

            tmpX += x[i];
            tmpY += y[i];
        }

        // cout << "curX: " << curX << " curY: " << curY << " tmpX: " << tmpX << " tmpY: " << tmpY << "\n";
        ans = min(ans, GetDist(curX, curY, tmpX, tmpY));
        return;
    }

    for(int i = idx; i < n; i++)
    {
        if(isUsed[i]) continue;

        isUsed[i] = true;
        GetAns(i + 1, curX + x[i], curY + y[i], cnt + 1);
        isUsed[i] = false;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int testCase;
    cin >> testCase;

    for(int t = 1; t <= testCase; t++)
    {
        cin >> n;
        
        for(int i = 0; i < n; i++)
        {
            cin >> x[i] >> y[i];
        }

        ans = LLONG_MAX;
        GetAns(0, 0, 0, 0);

        cout << "#" << t << " " << ans << "\n";
    }
    

    return 0;
}
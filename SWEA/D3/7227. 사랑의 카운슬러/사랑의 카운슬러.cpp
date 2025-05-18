#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;

ll ans = 0;

ll x[21];
ll y[21];

bool isUsed[21];

void GetAns(int idx, int cnt)
{
    // 전체 지렁이의 절반이 모두 움직였다면 크기 비교
    if(cnt == n / 2)
    {
        ll curX = 0;
        ll curY = 0;

        for(int i = 0; i < n; i++)
        {
            // 움직인 지렁이의 좌표는 더함
            if(isUsed[i])
            {
                curX += x[i];
                curY += y[i];
            }

            // 안 움직인 지렁이의 좌표는 뺌
            else
            {
                curX -= x[i];
                curY -= y[i];
            }
        }

        if(ans > curX * curX + curY * curY) ans = curX * curX + curY * curY;

        return;
    }

    for(int i = idx; i < n; i++)
    {
        if(isUsed[i]) continue;

        isUsed[i] = true;
        GetAns(i + 1, cnt + 1);
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
        n;
        cin >> n;

        for(int i = 0; i < n; i++)
        {
            cin >> x[i] >> y[i];
        }

        ans = LLONG_MAX;
        fill(isUsed, isUsed + 21, false);
        GetAns(0, 0);

        cout << "#" << t << " " << ans << "\n";
    }

    return 0;
}
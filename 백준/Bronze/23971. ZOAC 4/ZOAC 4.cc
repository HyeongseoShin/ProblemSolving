#include <bits/stdc++.h>

using namespace std;

int rCnt = 0;
int cCnt = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int h, w, n, m;

    cin >> h >> w >> n >> m;

    for(int i = 0; i < h; i+= (n + 1))
    {
        rCnt++;
    }

    for(int j = 0; j < w; j += (m + 1))
    {
        cCnt++;
    }

    long long ans = rCnt * cCnt;

    cout << ans << "\n";

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int testCase;
    cin >> testCase;

    for(int t = 1; t <= testCase; t++)
    {
        int n;
        cin >> n;

        int tree[101];

        int maxH = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> tree[i];
            maxH = max(maxH, tree[i]);
        }

        int twoCnt = 0;
        int oneCnt = 0;

        for(int i = 0; i < n; i++)
        {
            twoCnt += (maxH - tree[i]) / 2;
            oneCnt += (maxH - tree[i]) % 2;
        }

        while(twoCnt - oneCnt > 1)
        {
            twoCnt--;
            oneCnt += 2;
        }

        int ans = 0;

        if(oneCnt > twoCnt) ans = oneCnt * 2 - 1;
        else if(twoCnt > oneCnt) ans = twoCnt * 2;
        else ans = oneCnt + twoCnt;

        cout << "#" << t << " " << ans << "\n";
    }
    return 0;
}
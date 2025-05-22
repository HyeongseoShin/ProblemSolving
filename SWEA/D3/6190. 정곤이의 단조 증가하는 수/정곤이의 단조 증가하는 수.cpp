#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool isIncreasing(ll target)
{
    ll prev = target % 10;
    target /= 10;

    while(target > 0)
    {
        if(prev < target % 10) return false;

        prev = target % 10;
        target /= 10;
    }

    return true;
}

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

        int nums[1001];

        for(int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }

        ll ans = 0;

        for(int i = 0; i < n - 1; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                ll tmp = nums[i] * nums[j];

                if(isIncreasing(tmp)) ans = max(ans, tmp);
            }
        }

        cout << "#" << t << " ";

        if(ans == 0) ans = -1;

        cout << ans << "\n";
    }

    return 0;
}
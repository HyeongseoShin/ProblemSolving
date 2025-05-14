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

        vector<pair<int, int>> v;

        for(int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            v.push_back({a, b});
        }


        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            auto [curA, curB] = v[i];
            for(int j = i + 1; j < n; j++)
            {
                auto [nxtA, nxtB] = v[j];

                if(curA < nxtA && curB > nxtB) ans++;
                else if(curA > nxtA && curB < nxtB) ans++;
            }
        }

        cout << "#" << t << " " << ans << "\n";
    }

    return 0;
}
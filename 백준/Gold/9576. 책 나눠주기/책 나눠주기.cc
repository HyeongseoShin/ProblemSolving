#include <bits/stdc++.h>

using namespace std;

int n, m;

int t;

int ans = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while(t--)
    {
        ans = 0;
        cin >> n >> m;

        bool isUsed[1001];
        memset(isUsed, false, sizeof(isUsed));

        vector<pair<int, int>> v;

        for(int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;

            v.push_back({b, a});
        }

        sort(v.begin(), v.end());

        for(auto [b, a] : v)
        {
            for(int i = a; i <= b; i++)
            {
                if(isUsed[i]) continue;

                isUsed[i] = true;
                ans++;
                break;
            }
        }

        cout << ans << "\n";
    }

    

    return 0;
}
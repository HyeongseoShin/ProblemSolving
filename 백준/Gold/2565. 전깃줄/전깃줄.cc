int n;

#include <bits/stdc++.h>

using namespace std;

vector<int> lis;

vector<pair<int, int>> v;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++)
    {
        auto [a, b] = v[i];

        if(lis.empty() || lis.back() <= b) lis.push_back(b);
        else
        {
            auto idx = lower_bound(lis.begin(), lis.end(), b) - lis.begin();
            lis[idx] = b;
        }
    }

    cout << n - (int)lis.size() << "\n";



    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> v;

    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    vector<int> lis;

    for(int i = 0; i < n; i++)
    {
        if(!lis.empty() && lis.back() >= v[i])
        {
            int tmpIdx = lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin();
            lis[tmpIdx] = v[i];
        }

        else lis.push_back(v[i]);
    }

    cout << (int)lis.size() << "\n";

    return 0;
}
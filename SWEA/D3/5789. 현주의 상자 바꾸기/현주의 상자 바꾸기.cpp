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
        int n, q;
        cin >> n >> q;

        vector<int> v(n+1, 0);

        for(int i = 1; i <= q; i++)
        {
            int from, to;
            cin >> from >> to;

            fill(v.begin() + from, v.begin() + to + 1, i);
        }

        cout << "#" << t << " ";

        for(int i = 1; i <= n; i++)
        {
            cout << v[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
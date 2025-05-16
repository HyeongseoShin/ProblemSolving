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
        int l, u, x;
        cin >> l >> u >> x;

        cout << "#" << t << " ";

        if(x < l) cout << l - x << "\n";
        else if(x > u) cout << "-1\n";
        else if(l <= x && x <= u) cout << "0\n";

    }

    return 0;
}
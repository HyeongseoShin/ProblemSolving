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
        int d, h, m;
        cin >> d >> h >> m;

        int dDiff, hDiff;

        dDiff = d - 11;
        hDiff = (h * 60 + m) - (11 * 60 + 11);

        cout << "#" << t << " ";
        if(dDiff < 0 || (dDiff == 0 && hDiff < 0)) cout << "-1\n";
        else cout << dDiff * 24 * 60 + hDiff << "\n";
    }
    return 0;
}
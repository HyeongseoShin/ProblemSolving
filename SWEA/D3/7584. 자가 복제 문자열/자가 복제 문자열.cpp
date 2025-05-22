#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int testCase;
    cin >> testCase;

    for(int t = 1; t <= testCase; t++)
    {
        ll k;
        cin >> k;

        k--;

        while(k % 2 == 1) k /= 2;

        cout << "#" << t << " ";
        if(k % 4 == 0) cout << "0\n";
        else if(k % 2 == 0) cout << "1\n";
    }
    return 0;
}
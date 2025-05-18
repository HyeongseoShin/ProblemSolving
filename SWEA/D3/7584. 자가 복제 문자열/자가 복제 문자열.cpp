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

        // 0 - indexed
        k--;
        
        int ans = 0;
        
        while(k % 2 == 1) k = (k-1) / 2;

        if(k % 4 == 0) ans = 0;
        else if(k % 2 == 0) ans = 1;

        cout << "#" << t << " " << ans << "\n";
    }

    return 0;
}
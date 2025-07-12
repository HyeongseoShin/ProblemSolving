#include <bits/stdc++.h>

using namespace std;

int n;

int ans = INT_MAX;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i * 5 <= n; i++)
    {
        for(int j = 0; i * 5 + j * 3 <= n; j++)
        {
            if(i * 5 + j * 3 == n)
            {
                ans = min(ans, i + j);
            }
            
        }
    }

    if(ans == INT_MAX) ans = -1;

    cout << ans << "\n";

    return 0;
}
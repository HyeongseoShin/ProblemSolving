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
        int n, d;
        cin >> n >> d;
        

        int sz = 1 + 2 * d;
        int idx = sz;
        int ans = 1;
        
        while(idx < n)
        {
            idx += sz;
            ans++;
        }
        
        cout << "#" << t << " " << ans << "\n";
    }
    return 0;
    
}
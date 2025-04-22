#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    
    cin >> t;
    
    while(t--)
    {
        int n, p;
        int cur = 0;
        
        cin >> n >> p;
        
        for(int i = 1; i <= n; i++)
        {
			cur += i;
            if(cur == p) cur--;
        }
        
        cout << cur << "\n";
    }
    return 0;
}
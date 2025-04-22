#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
	cin >> n;
    
    while(n--)
    {
        int maxH = 0;
        int sum = 0;
        
        for(int i = 0; i < 6; i++)
        {
            int x;
            cin >> x;
            sum += x;
            maxH = max(maxH, x);
        }
        
        
        int ans = 0;
        for(int i = maxH + 1; i <= INT_MAX; i++)
        {
            // cout << "sum: " << sum << " i: " << i << "\n";
            if((sum + i) % 7 == 0)
            {
                ans = i;
                break;
            }
        }
        
        cout << ans << "\n";
    }
    return 0;
}
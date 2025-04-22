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
        int n;
        cin >> n;
        
        bool isPossible = true;
        string ans = "";
        
        if(n % 3 == 1)
        {
            isPossible = false;
            cout << "impossible\n";
        }

        else if(n % 3 == 2)
        {
            ans += "BA";
        }
        
        if(isPossible)
        {
            for(int i = 0; i < n / 3; i++)
            {
                ans += "BBA";
            }
            cout << ans << "\n";
        }
        
    }
    
	return 0;
}
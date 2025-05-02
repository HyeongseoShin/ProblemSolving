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
        bool isPossible = false;
        
        ll n, d, g;
        cin >> n  >> d >> g;
        
        cout << "#" << t << " ";
        
        if((d != 0 && g == 0) || (d != 100 && g == 100))
        {
            cout << "Broken\n";
			continue;
        }
        

        else
        {
            for(ll i = 1; i <= n; i++)
            {
				if(i * d % 100 == 0)
                {
                    isPossible = true;
                    break;
                }
            }

        }

        if(isPossible) cout << "Possible\n";
        else cout << "Broken\n";
        
        
    }
    return 0;
}
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
        ll n;
        
        cin >> n;
        ll ans = n - 1;
       
        for(ll i = 2; i <= sqrt(n); i++)
        {
            if(n % i == 0)
            {
                ans = min(ans, (i - 1) + (n / i - 1));
            }
        }
        
        cout << "#" << t << " " << ans << "\n";
        
    }
    return 0;
}
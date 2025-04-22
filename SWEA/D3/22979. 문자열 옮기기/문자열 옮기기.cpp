#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t;
string s;

int main()
{
	cin >> t;
    
    while(t--)
    {
        cin >> s;
        
        int n;
        cin >> n;

        ll sum = 0;
        
        while(n--)
        {
            ll x;
            cin >> x;
            
            sum += x;
            
        }
        
        string result = "";
        

		if(sum > 0)
        {
            ll cnt = sum % (ll)s.length();

            result += s.substr(cnt, (ll)s.length());
            result += s.substr(0, cnt);

            cout << result << "\n";
        }
        
		else if(sum < 0)
        {
            sum = abs(sum);
            ll cnt = sum % (ll)s.length();

            result += s.substr((ll)s.length() - cnt, (ll)s.length());
            result += s.substr(0, (ll)s.length() - cnt);
			
            cout << result << "\n";
        }        
        
        else
        {
            cout << s << "\n";
        }

            
    }
	return 0;
}
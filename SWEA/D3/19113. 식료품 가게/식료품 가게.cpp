#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int test;
    cin >> test;
    
    for(int t = 1; t <= test; t++)
    {
        ll n;
        cin >> n;
        
        vector<ll> v;
       	vector<bool> isUsed;
        
        for(int i = 0; i < n * 2; i++)
        {
            ll x;
            cin >> x;
            
            v.push_back(x);
            isUsed.push_back(false);
        }
        
        vector<ll> ans;
        cout << "#" << t << " ";
        for(int i = n * 2 - 1; i > 0; i--)
        {
            if(isUsed[i]) continue;
            if(v[i] % 4 != 0) continue;            
            
            for(int j = i - 1; j >= 0; j--)
            {
                if(isUsed[j]) continue;
                if(v[i]  / 4 * 3 == v[j])
                {
                    isUsed[i] = true;
                    isUsed[j] = true;
                    
                    ans.push_back(v[j]);
                    
                    break;
                }
            }
            
        }
        
		sort(ans.begin(), ans.end());
        
        for(int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
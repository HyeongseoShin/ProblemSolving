#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //int testCase;
    //cin >> testCase;
    
    for(int t = 1; t <= 10; t++)
    {
        int n;
        cin >> n;
        
        vector<int> v;
        
        v.push_back(0);
        v.push_back(0);
        
        for(int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
        
        v.push_back(0);
        v.push_back(0);
        
        int ans = 0;
        for(int i = 2; i < n + 2; i++)
        {
            int maxVal = 0;
			for(int j = i - 2; j <= i - 1; j++)
            {
                maxVal = max(maxVal, v[j]);
            }
            
            for(int j = i + 1; j <= i + 2; j++)
            {
                maxVal = max(maxVal, v[j]);
            }
            
            if(v[i] - maxVal > 0) ans += (v[i] - maxVal);
        }
        
        cout << "#" << t << " " << ans << "\n";
        
    }
    return 0;
}
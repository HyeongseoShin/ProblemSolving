#include <bits/stdc++.h>

using namespace std;

int  main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for(int t = 1; t <= 10; t++)
    {
        int n;
        cin >> n;
        
        string s, target;
        cin >> s >> target;
        
        int ans = 0;
        for(int i = 0; i < (int)target.length(); i++)
        {
        	string tmp = "";
            for(int j = i; j < i + (int)s.length() && j < (int)target.length(); j++)
            {
                tmp += target[j];
            }
            if(tmp == s) ans++;
        }
        
        cout << "#" << n << " " << ans << "\n";
    }
    return 0;
}
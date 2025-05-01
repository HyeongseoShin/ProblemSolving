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
        string s;
        cin >> s;
        
        int cnt = 0;
        
        for(int i = 0; i < (int)s.length(); i++)
        {
            if(s[i] == 'o') cnt++;
        }
        
        cout << "#" << t << " ";
        if(15 - (int)s.length() + cnt >= 8) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
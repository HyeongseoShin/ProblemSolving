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
        string tmp, s1, s2;
        cin >> s1 >> s2;
        
        int n = (int)s1.length();
        int m = (int)s2.length();
        
        if(n > m)
        {
            tmp = s1;
            s1 = s2;
            s2 = tmp;
        }
        
        n = (int)s1.length();
        m = (int)s2.length();
        
        int idx = 0;
        for(int i = 0; i < m - n + m; i++)
        {
            s1 += s1[idx];
            
            idx = (idx + 1) % n;
        }
        
        s2 += s2;
        // cout << s1 << " " << s2 << "\n";
        cout << "#" << t << " ";
        if(s1 == s2) cout << "yes\n";
        else cout << "no\n";
        
        
    }
    return 0;
}
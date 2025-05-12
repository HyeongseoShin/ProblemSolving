#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for(int t = 1; t <= 10; t++)
    {
        int n;
        cin >> n;
        
        string s;
		cin >> s;
        
        int st = 0;
        int en = 1;
        
        bool isRemoved[100];
        fill(isRemoved, isRemoved + 100, false);
        
        while(en < n && st < en)
        {
            if(s[st] != s[en])
            {
                st++;
                en++;
            }
            
            while(st >= 0 && en < n && s[st] == s[en])
            {
                isRemoved[st] = true;
                isRemoved[en] = true;
                
                while(isRemoved[st]) st--;
                while(isRemoved[en]) en++;
            }
            
            // cout << "st: " << st <<" en: " << en << "\n";
            
            st = en;
            en++;
            

        }
        
        string ans = "";
        for(int i = 0; i < n; i++)
        {
            if(!isRemoved[i]) ans += s[i];
        }
        
        cout << "#" << t << " " << ans << "\n";
        
    }
    return 0;
}
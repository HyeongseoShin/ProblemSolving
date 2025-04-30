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
            if(s[i] == '(') cnt++;
            else if(i > 0 && s[i] == ')' && s[i-1] != '(') cnt++; 
        }
        
        cout << "#" << t << " " << cnt << "\n";
    }
    
    
}
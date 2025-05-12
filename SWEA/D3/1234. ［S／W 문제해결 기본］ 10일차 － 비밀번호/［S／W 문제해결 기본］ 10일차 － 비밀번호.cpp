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
        
        stack<char> stk;
        
        for(int i = 0; i < n; i++)
        {
            if(!stk.empty() && stk.top() == s[i]) stk.pop();
            else stk.push(s[i]);
        }
        
        string tmp = "";
        
        while(!stk.empty())
        {
            tmp += stk.top();
            stk.pop();
        }
        
        reverse(tmp.begin(), tmp.end());
        cout << "#" << t << " " << tmp << "\n";
    }
    return 0;
}
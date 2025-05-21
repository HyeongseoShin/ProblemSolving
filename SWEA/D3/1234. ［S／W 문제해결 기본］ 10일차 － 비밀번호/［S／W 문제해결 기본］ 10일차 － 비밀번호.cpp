#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int t = 1; t <= 10; t++)
    {
        int n;
        string s;

        cin >> n >> s;

        stack<char> stk;

        for(int i = 0; i < n; i++)
        {
            bool isPossible = true;
            while(!stk.empty() && stk.top() == s[i])
            {
                isPossible = false;
                stk.pop();
            }
            
            if(isPossible) stk.push(s[i]);
        }

        string ans = "";

        while(!stk.empty())
        {
            ans += stk.top();
            stk.pop();
        }

        reverse(ans.begin(), ans.end());

        cout << "#" << t << " " << ans << "\n";
    }

    return 0;
}
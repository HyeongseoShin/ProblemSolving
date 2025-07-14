#include <bits/stdc++.h>

using namespace std;

int n, k;
string s;
string ans;

stack<char> stk;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    cin >> s;

    for(int i = 0; i < (int)s.length(); i++)
    {
        while(k > 0 && !stk.empty() && stk.top() < s[i])
        {
            stk.pop();
            k--;
        }
        stk.push(s[i]);
    }

    
    while(!stk.empty())
    {
        if(k == 0) ans += stk.top();
        stk.pop();
        if(k > 0) k--;
    }

    reverse(ans.begin(), ans.end());
    cout << ans << "\n";

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

string s;
string bomb;

stack<char> stk;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    cin >> bomb;

    int n1 = s.length();
    int n2 = bomb.length();

    char lastChar = bomb[n2-1];

    int idx;
    for(int i = 0; i < n1; i++)
    {
        stk.push(s[i]);

        if(s[i] == lastChar)
        {
            idx = n2 - 1;
            string tmp = "";

            while(!stk.empty() && idx >= 0 && stk.top() == bomb[idx--])
            {
                tmp += stk.top();
                stk.pop();
            }
            
            reverse(tmp.begin(), tmp.end());

            if(tmp != bomb)
            {
                for(int j = 0; j < tmp.length(); j++)
                {
                    stk.push(tmp[j]);
                }
            }
        }
    }

    string ans = "";
    while(!stk.empty())
    {
        // cout << stk.top();
        ans += stk.top();
        stk.pop();
    }

    if(ans == "") cout << "FRULA" << "\n";
    else
    {
        reverse(ans.begin(), ans.end());
        cout << ans << "\n";
    }

    return 0;
}
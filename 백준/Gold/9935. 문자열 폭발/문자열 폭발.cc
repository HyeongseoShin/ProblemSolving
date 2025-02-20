// https://www.acmicpc.net/problem/9935
// 스택

// 스스로 못풂
#include <bits/stdc++.h>

using namespace std;

int n;
string s;
string bomb;
stack<char> stk;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    cin >> bomb;

    n = s.length();

    int idx = bomb.length() - 1;
    char last = bomb[idx];
    
    for(int i = 0; i < n; i++)
    {
        stk.push(s[i]);

        if(stk.top() == last)
        {
            string tmp;

            for(int j = 0; j < bomb.length() && !stk.empty(); j++)
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

    if(stk.empty()) cout << "FRULA" << "\n";

    else
    {
        string ans;
        while(!stk.empty())
        {
            ans += stk.top();
            stk.pop();
        }

        reverse(ans.begin(), ans.end());

        cout << ans << "\n";
    }
    
    return 0;
}
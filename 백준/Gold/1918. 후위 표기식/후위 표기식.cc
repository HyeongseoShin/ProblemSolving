#include <bits/stdc++.h>

using namespace std;

string s;

unordered_map<char, int> um;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    um['('] = 0;
    um[')'] = 0;

    um['*'] = 1;
    um['/'] = 1;

    um['+'] = 2;
    um['-'] = 2;

    cin >> s;

    stack<char> stk;
    for(int i = 0; i < (int)s.length(); i++)
    {
        char cur = s[i];
        
        if('A' <= cur && cur <= 'Z') cout << cur;
        
        // 기호라면
        else
        {
            // 괄호 끝날 때까지 
            if(cur == ')')
            {
                while(!stk.empty() && stk.top() != '(')
                {
                    cout << stk.top();
                    stk.pop();
                }

                // if(!stk.empty()) stk.pop();
                stk.pop();
            }
            
            else
            {
                while(!stk.empty() && stk.top() != '(' && um[stk.top()] <= um[cur])
                {
                    cout << stk.top();
                    stk.pop();
                }

                stk.push(cur);
            }
        }
    }

    while(!stk.empty())
    {
        cout << stk.top();
        stk.pop();
    }

    cout << "\n";

    return 0;
}
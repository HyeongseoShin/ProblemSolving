#include <bits/stdc++.h>

using namespace std;

string s;

unordered_map<char, int> um;

string ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;

    um['('] = 0;
    um[')'] = 0;

    um['*'] = 1;
    um['/'] = 1;

    um['+'] = 2;
    um['-'] = 2;

    stack<char> stk;

    for(int i = 0; i < (int)s.length(); i++)
    {
        char cur = s[i];

        // 기호라면
        if(um.find(cur) != um.end())
        {
            // '(' 만날 때까지 pop
            if(cur == ')')
            {
                while(!stk.empty() && stk.top() != '(')
                {
                    ans += stk.top();
                    stk.pop();
                }

                // stack이 비지 않으면 마지막 '(' 제거
                if(!stk.empty()) stk.pop();
            }

            else
            {
               while(!stk.empty() && stk.top() != '(' && um[stk.top()] <= um[cur])
               {
                    if(stk.top() == '(' || stk.top() == ')')
                    {
                        stk.pop();
                        continue;
                    }

                    ans += stk.top();
                    stk.pop();
               }

               stk.push(cur);
                 
            }
            // while(!stk.empty() && stk.top() != '(' && um[stk.top()] <= um[cur])
            // {
            //     if(stk.top() == '(' || stk.top() == ')')
            //     {
            //         stk.pop();
            //         continue;
            //     }

            //     cout << um[stk.top()] << " " << um[cur] << "\n";
            //     ans += stk.top();
            //     stk.pop();
            // }

            
        }

        else
        {
            ans += cur;
        }
    }

    while(!stk.empty())
    {
        if(stk.top() == '(' || stk.top() == ')')
        {
            stk.pop();
            continue;
        }
        ans += stk.top();
        stk.pop();
    }

    cout << ans << "\n";


    return 0;
}
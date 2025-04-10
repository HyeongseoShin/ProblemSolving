#include <bits/stdc++.h>

using namespace std;

int n;
string s;

unordered_map<char, int> um;

stack<double> stk;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cin >> s;

    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        um['A' + i] = x;
    }

    for(int i = 0; i < (int)s.length(); i++)
    {
        // 문자이면 치환 후 스택에 넣기
        if(um.find(s[i]) != um.end())
        {
            stk.push(um[s[i]]);
        }

        // 기호라면
        else
        {
            double a = stk.top();
            stk.pop();

            double b = stk.top();
            stk.pop();

            switch(s[i])
            {
                case '+':
                    stk.push(b + a);
                    break;
                case '-':
                    stk.push(b - a);
                    break;
                case '*':
                    stk.push(b * a);
                    break;
                case '/':
                    stk.push(b / a);
                    break;
            }
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << stk.top() << "\n";

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

string s;

stack<char> stk;
vector<char> v; // 현재 스택의 마지막 4자리 확인하기 위한 용도

// 현재 스택의 마지막 4자리가 PPAP인지 확인
void check()
{
    int len = (int)v.size();

    // 마지막 4자리가 PPAP라면
    if(v[len-1] == 'P' && v[len-2] == 'A' && v[len-3] == 'P' && v[len-4] == 'P')
    {
        for(int i = 0; i < 4; i++)
        {
            stk.pop();
            v.pop_back();
        }

        stk.push('P');
        v.push_back('P');
    }

    
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;

    for(int i = 0; i < (int)s.length(); i++)
    {
        if((int)stk.size() >= 4) check();

        stk.push(s[i]);
        v.push_back(s[i]);
    }

    string ans = "";
    while(!stk.empty())
    {
        ans += stk.top();
        stk.pop();
    }

    reverse(ans.begin(), ans.end());

    // cout << "ans: " << ans << "\n";
    if(ans == "PPAP" || ans == "P") cout << "PPAP\n";
    else cout << "NP\n";

    
    return 0;
}
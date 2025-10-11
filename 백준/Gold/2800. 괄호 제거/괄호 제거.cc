#include <bits/stdc++.h>

using namespace std;

set<string> ans; // 정답

string s;

stack<int> stk; // 괄호 확인 스택
vector<pair<int,int>> v; // 괄호 <시작, 끝>

bool isDeleted[11];

void GetAns(int cur)
{
    if(cur >= (int)v.size())
    {   
        set<int> pos;
        for(int i = 0; i < (int)v.size(); i++)
        {
            if(isDeleted[i])
            {
                auto [st, en] = v[i];
                pos.insert(st);
                pos.insert(en);
            }
        }

        string newS = "";
        for(int i = 0; i < (int)s.length(); i++)
        {
            if(pos.count(i) > 0) continue;
            newS += s[i];
        }

        if(newS == s) return;

        ans.insert(newS);
        return;
    }

    for(int i = cur; i < (int)v.size(); i++)
    {
        isDeleted[i] = true;
        GetAns(i+1);
        isDeleted[i] = false;
        GetAns(i+1);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;

    for(int i = 0; i < (int)s.length(); i++)
    {
        if(s[i] == '(') stk.push(i);
        else if(s[i] == ')')
        {
            v.push_back({stk.top(), i});
            stk.pop();
        }
    }

    GetAns(0);

    for(auto word : ans)
    {
        cout << word << "\n";
    }

    return 0;
}
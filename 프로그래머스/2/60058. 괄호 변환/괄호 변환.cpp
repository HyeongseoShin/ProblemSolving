#include <bits/stdc++.h>

using namespace std;

string answer = "";

string split(string s)
{
    if(s.empty()) return "";
    
    string u = "", v = "";
    int idx = 0, open = 0, close = 0;
    for(int i = 0; i < (int)s.length(); i++)
    {
        u += s[i];
        if(s[i] == '(') open++;
        else if(s[i] == ')') close++;
        
        if(open == close)
        {
            idx = i+1;
            break;
        }
    }
    
    if(idx < (int)s.length()) v = s.substr(idx, (int)s.length() - idx);
    
    stack<char> stk;
    for(auto c : u)
    {
        if(c == '(') stk.push(c);
        else if(!stk.empty()) stk.pop();
    }
    
    if(stk.empty())
    {
        u += split(v);
        return u;
    }
    else
    {
        string newS = "(";
        newS += split(v);
        newS += ')';
        
        for(int i = 1; i < (int)u.length() - 1; i++)
        {
            char cur;
            if(u[i] == '(') cur = ')';
            else cur = '(';
            newS += cur;
        }
        
        return newS;
    }
    
}
string solution(string p) {
    answer = split(p);
    
    return answer;
}
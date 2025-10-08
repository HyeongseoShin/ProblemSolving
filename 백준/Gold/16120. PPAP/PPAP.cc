#include <bits/stdc++.h>

using namespace std;

string s;

stack<char> stk;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;

    int pCnt = 0; // 이전까지 P 나온 횟수
    for(int i = 0; i < (int)s.length(); i++)
    {
        if(s[i] == 'P')
        {
            if(pCnt >= 2 && stk.top() == 'A') // 현재 P 이고 이전까지 PPA 이면 => PPAP
            {
                for(int i = 0; i < 3; i++) stk.pop(); // PPA pop();

                if(!stk.empty() && stk.top() == 'P') pCnt = 1; // stk.top()이 P이면 pCnt = 1
                else pCnt = 0;
            }

            pCnt++;
        }

        else
        {
            if(pCnt < 2) pCnt = 0; // A 등장 전에 P가 2번 미만으로 나옴 => 불가능
            else if(!stk.empty() && stk.top() == 'A') pCnt = 0; // A 전에 A가 나옴 => 불가능
        }

        stk.push(s[i]);
        
    }

    string ans = "";
    while(!stk.empty())
    {
        ans += stk.top();
        stk.pop();
    }

    reverse(ans.begin(), ans.end());

    if(ans == "PPAP" || ans == "P") cout << "PPAP\n";
    else cout << "NP\n";
    
    return 0;
}
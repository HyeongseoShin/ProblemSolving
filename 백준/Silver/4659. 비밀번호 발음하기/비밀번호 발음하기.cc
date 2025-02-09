// https://www.acmicpc.net/problem/4659

#include <bits/stdc++.h>

using namespace std;


bool isVowel(char c)
{
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
    else return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(true)
    {
        string s;

        cin >> s;

        if(s == "end") break;

        int n = (int)s.length();

        bool isPossible = false;

        for(int i = 0; i < n; i++)
        {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            {
                isPossible = true;
                break;
            }
        }
        
        if(!isPossible)
        {
            cout << "<" << s << "> is not acceptable.\n";
            continue;
        }

        isPossible = true;
        for(int i = 1; i < n - 1; i++)
        {
            if((isVowel(s[i-1]) && isVowel(s[i]) && isVowel(s[i+1])) || (!isVowel(s[i-1]) && !isVowel(s[i]) && !isVowel(s[i+1])))
            {
                isPossible = false;
                break;
            }
        }
        if(!isPossible)
        {
            cout << "<" << s << "> is not acceptable.\n";
            continue;
        }

        isPossible = true;
        for(int i = 0; i < n - 1; i++)
        {
            if(s[i] == s[i+1] && s[i] != 'e' && s[i] != 'o')
            {
                isPossible = false;
                break;
            }
        }
        if(!isPossible)
        {
            cout << "<" << s << "> is not acceptable.\n";
            continue;
        }

        cout << "<" << s << "> is acceptable.\n";
    }
    return 0;
}

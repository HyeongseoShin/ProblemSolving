#include <bits/stdc++.h>

using namespace std;

int t;

// 회문인지 검사
bool isPalindrome(string s, int st, int en)
{
    while(st < en)
    {
        if(s[st] != s[en]) return false;
        
        st++;
        en--;
    }

    return true;
}

// 회문 검사
int check(string s)
{
    int n = (int)s.length();
    int st = 0;
    int en = n - 1;

    while(st < en)
    {
        if(s[st] == s[en])
        {
            st++;
            en--;
        }

        else
        {
            // 유사 회문인지 검사
            if(isPalindrome(s, st+1, en) || isPalindrome(s, st, en-1)) return 1;
            
            // 그 외 문자열
            else return 2;
        }
    }

    // 회문
    return 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while(t--)
    {
        string s;
        cin >> s;

        cout << check(s) << "\n";        
    }

    return 0;
}
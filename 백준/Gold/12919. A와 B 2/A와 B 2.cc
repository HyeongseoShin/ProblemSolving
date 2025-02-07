// https://www.acmicpc.net/problem/12919
#include <bits/stdc++.h>

using namespace std;

void Test(string s, string t)
{
    if(s == t)
    {
        cout << "1\n";
        exit(0);
    }

    if(s.length() > t.length())
    {
        return ;
    }

    if(t[t.length() - 1] == 'A')
    {
        string tmp = t;
        tmp.erase(tmp.length()-1);
        Test(s, tmp);
    }

    if(t[0] == 'B')
    {
        string tmp = t;
        reverse(tmp.begin(), tmp.end());
        tmp.erase(tmp.length()-1);
        Test(s, tmp);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s, t;
    cin >> s >> t;

    Test(s, t);

    cout << "0\n";

    return 0;
}
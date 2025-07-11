#include <bits/stdc++.h>

using namespace std;

string s;
string t;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s >> t;

    while((int)s.length() < (int)t.length())
    {
        int last = t.length() - 1;

        if(t[last] == 'A') t = string(t.begin(), t.end() - 1);
        else
        {
            t = string(t.begin(), t.end() - 1);
            reverse(t.begin(), t.end());
        }
    }

    if(s == t) cout << "1\n";
    else cout << "0\n";

    return 0;
}
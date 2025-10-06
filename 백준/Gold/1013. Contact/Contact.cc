#include <bits/stdc++.h>

using namespace std;

int t;

bool isMatching(string s)
{
    regex e("(100+1+|01)+");
    return regex_match(s, e);
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

        if(isMatching(s)) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
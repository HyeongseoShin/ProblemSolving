#include <bits/stdc++.h>

using namespace std;

string s;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;

    int cur = 0;
    int ans = 0;
    bool isMinus = false;

    for(int i = 0; i < s.length(); i++)
    {
        if(isdigit(s[i]))
        {
            cur = cur * 10 + (s[i] - '0');
        }

        else
        {
            if(isMinus) ans -= cur;
            else ans += cur;

            if(s[i] == '-') isMinus = true;

            cur = 0;
            
        }
    }

    if(isMinus) ans -= cur;
    else ans += cur;

    cout << ans << "\n";


    return 0;
}
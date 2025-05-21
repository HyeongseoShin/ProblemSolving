#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int t = 1; t <= 10; t++)
    {
        int n;
        string s;

        cin >> n >> s;

        for(int i = 0; i < n - 1; i++)
        {
            if(s[i] == ' ') continue;
            if(s[i] != s[i+1]) continue;

            int st = i;
            int en = i + 1;

            while(st >= 0 && en < n && s[st] == s[en])
            {
                s[st] = ' ';
                s[en] = ' ';

                while(st > 0 && s[st] == ' ') st--;
                while(en < n - 1 && s[en] == ' ') en++;
            }
        }

        string ans = "";
        for(int i = 0; i < n; i++)
        {
            if(s[i] != ' ') ans += s[i];
        }
        cout << "#" << t << " " << ans << "\n";
    }
    return 0;
}
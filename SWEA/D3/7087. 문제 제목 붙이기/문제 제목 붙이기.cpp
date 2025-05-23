#include <bits/stdc++.h>

using namespace std;

int main()
{    
    ios::sync_with_stdio(0);
    cin.tie(0);

    int testCase;
    cin >> testCase;


    for(int t = 1; t <= testCase; t++)
    {
        int n;
        cin >> n;

        int cnt[26];
        fill(cnt, cnt + 26, 0);

        for(int i = 0; i < n; i++)
        {
            string s;
            cin >> s;

            cnt[s[0] - 'A']++;
        }

        int ans = 26;
        for(int i = 0; i < 26; i++)
        {
            if(cnt[i] == 0)
            {
                ans = i;
                break;
            }
        }

        cout << "#" << t << " " << ans << "\n";
    }
    return 0;
}
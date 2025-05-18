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

        string s;

        for(int i = 0; i < n; i++)
        {
            char c;
            cin >> c;

            s += c;
        }

        int ans = 0;

        while(true)
        {
            string strAns = to_string(ans);
            if(s.find(to_string(ans)) == string::npos) break;

            ans++;
        }

        cout << "#" << t << " " << ans << "\n";
    }

    return 0;
}
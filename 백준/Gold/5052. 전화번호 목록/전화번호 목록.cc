#include <bits/stdc++.h>

using namespace std;

int t, n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;

        bool isOk = true;

        vector<string> v;

        for(int i = 0; i < n; i++)
        {
            string s;
            cin >> s;

            v.push_back(s);
            
        }

        sort(v.begin(), v.end());

        for(int i = 0; i < n - 1; i++)
        {
            if(v[i+1].substr(0, (int)v[i].length()) == v[i])
            {
                isOk = false;
                break;
            }
        }

        if(isOk) cout << "YES\n";
        else cout << "NO\n";
        
    }

    return 0;
}
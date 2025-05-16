#include <bits/stdc++.h>

using namespace std;

int GetType(char c)
{
    if(c == 'A' || c == 'D' || c == 'O' || c == 'P' || c == 'Q' || c == 'R') return 1;
    else if(c == 'B') return 2;
    return 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int testCase;
    cin >> testCase;

    for(int t = 1; t <= testCase; t++)
    {
        string s1, s2;
        cin >> s1 >> s2;

        if((int)s1.length() != (int)s2.length())
        {
            cout << "#" << t << " DIFF\n";
            continue;
        }

        int n = (int)s1.length();

        bool isSame = true;
        for(int i = 0; i < n; i++)
        {
            if(GetType(s1[i]) != GetType(s2[i]))
            {
                isSame = false;
                break;
            }
        }

        cout << "#" << t << " ";
        if(isSame) cout << "SAME\n";
        else cout << "DIFF\n";
    }

    return 0;
}
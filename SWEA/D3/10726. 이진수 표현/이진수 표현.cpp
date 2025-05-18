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
        int n, m;
        cin >> n >> m;

        bool isPossible = true;

        while(n--)
        {
            if(((m >> n) & 1) == 0)
            {
                isPossible = false;
                break;
            }
        }

        cout << "#" << t << " ";

        if(isPossible)cout << "ON\n";
        else cout << "OFF\n";
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int testCase;
    cin >> testCase;

    for(int t = 1; t <= testCase; t++)
    {
        ll n, pD, pG;

        cin >> n >> pD >> pG;

        bool isPossible = false;
        if(pG == 100 && pD != 100) isPossible = false;
        else if(pG == 0 && pD != 0) isPossible = false;

        else
        {
            for(ll i = 1; i <= n; i++)
            {
                if(i * pD % 100 == 0)
                {
                    isPossible = true;
                    break;
                }
            }
        }
        
        cout << "#" << t << " ";
        if(isPossible) cout << "Possible\n";
        else cout << "Broken\n";
    }
    return 0;
}
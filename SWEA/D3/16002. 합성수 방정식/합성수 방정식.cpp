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
        ll n;
        cin >> n;
        
       cout << "#" << t << " " << 9 * n << " " << 8 * n << "\n";
        
    }
    return 0;
}
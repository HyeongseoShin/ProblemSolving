#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int testCase;
    cin >> testCase;
        
    for(int t = 1; t <= testCase; t++)
    {
		ll a, b;
        cin >> a >> b;
        
        ll diff = b - a;
        
        cout << "#" << t << " ";
        
		if(diff == 1 || diff < 0) cout << "-1\n";
       	else cout << diff / 2 << "\n";

    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    
    cin >> t;
    
    while(t--)
    {
        int l, r;
        
        cin >> l >> r;
        
        if(r + 1 <= l * 2) cout << "yes\n";
        else cout << "no\n";

    }
    return 0;
}
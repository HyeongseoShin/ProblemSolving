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
		cin >> s;
        
        cout << "#" << t << " ";
        if(n == 1) cout << "No\n";
        else if(s.substr(0, n / 2) == s.substr(n/2, n)) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
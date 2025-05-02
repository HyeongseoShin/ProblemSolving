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
        int a, b, c, d;
        
        cin >> a >> b >> c >> d;
        
        int st = max(a, c);
        int en = min(b, d);
        
        cout << "#" << t << " ";
        if(en - st < 0) cout << "0\n";
        else cout << en - st << "\n";
    }
    return 0;
}
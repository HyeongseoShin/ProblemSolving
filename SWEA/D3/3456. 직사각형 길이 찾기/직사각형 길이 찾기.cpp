#include <bits/stdc++.h>

using namespace std;

int main()
{
    int testCase;
    cin >> testCase;
    
    for(int t = 1; t <= testCase; t++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        
        multiset<int> ms;
        ms.insert(a);
        ms.insert(b);
        ms.insert(c);

        int ans = a;
        
        if(ms.count(b) % 2 == 1) ans = b;
        else if(ms.count(c) % 2 == 1) ans = c;

        cout << "#" << t << " " << ans << "\n";
    }
}
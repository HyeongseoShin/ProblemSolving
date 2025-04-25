#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int test;
    cin >> test;
    
    for(int t = 1; t <= test; t++)
    {
        int a, b, c;
        
        cin >> a >> b >> c;


        
        
        double ans;       
        double tmp1 = abs((double)(c + a) / 2 - b);
        double tmp2 = abs(b - (double)(c - b) - a);
        double tmp3 = abs(b + (double)(b - a) - c);
            
        ans = min(min(tmp1, tmp2), tmp3);
        
        cout << fixed;
        cout.precision(1);
        
        cout << "#" << t << " " << ans << "\n";
    }
    return 0;
}
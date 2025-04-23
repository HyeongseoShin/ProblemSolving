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
        
        int cnt = 0;
        
		if(b >= c)
        {
        	cnt += (b - (c - 1));
            b = c - 1;
            if(b <= 0)
            {
                cout << "#" << t << " -1\n";
                continue;
            }    
        }
        
        if(a >= b)
        {
        	cnt += (a - (b - 1));
            a = b - 1;
            if(a <= 0)
            {
                cout << "#" << t << " -1\n";
                continue;
            }    
        }
        
        cout << "#" << t << " " << cnt << "\n";
    }
    return 0;
}
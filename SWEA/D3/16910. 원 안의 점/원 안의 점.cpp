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
        
        int cnt = 0;
        cout << "#" << t << " ";
        for(int i = n * -1; i <= n; i++)
        {
            for(int j = n * -1; j <= n; j++)
            {
                if(i*i + j*j <= n*n) cnt++;
            }
        }
        
        cout << cnt << "\n";
    }
    return 0;
}
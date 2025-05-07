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
        int n, m, k;
        
        cin >> n >> m >> k;
        
        vector<int> v;
        
        for(int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
        
        sort(v.begin(), v.end());
        
        bool isPossible = true;
        for(int i = 0; i < n; i++)
        {
            if((v[i] / m) * k - i - 1 < 0)
            {
                isPossible = false;
                break;
            }
        }
        
        cout << "#" << t << " ";
        if(isPossible) cout << "Possible\n";
        else cout << "Impossible\n";
        
    }
    return 0;
}
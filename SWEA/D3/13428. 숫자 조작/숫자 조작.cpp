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
        string s;
        cin >> s;
        
        int n = (int) s.length();
        
        int minResult = stoi(s);
        int maxResult = stoi(s);
        for(int i = 0; i < n - 1; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                string result = s;
                char tmp = result[i];
                result[i] = result[j];
                result[j] = tmp;
                
                if(result[0] == '0') continue;
                
                minResult = min(minResult, stoi(result));
                maxResult = max(maxResult, stoi(result));
                
            }
        }
        
        cout << "#" << t << " " << minResult << " " << maxResult << "\n";
        
    }
    return 0;
    
}
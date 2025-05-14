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
        
        vector<string> v;
        for(int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            v.push_back(s);
        }
        
        int stA = 0;
        int stB = (n+1) / 2;
        
        cout << "#" << t << " ";
        while(true)
        {
			if(stA >= (n+1) / 2 && stB >= n) break;
            
            if(stA < (n+1) / 2) cout << v[stA++] << " ";
            if(stB < n) cout << v[stB++] << " ";
        }
        cout << "\n";
        
    }
	return 0;
}
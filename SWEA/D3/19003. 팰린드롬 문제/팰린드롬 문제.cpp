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
        int n, m;
        cin >> n >> m;
        
        int cnt = 0;
        
        vector<string> v;
        
        for(int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            
            if(s != string(s.rbegin(), s.rend()))	v.push_back(s);
            else cnt = 1;
        }
        
        if(!v.empty())
        {
            for(int i = 0; i < (int)v.size() - 1; i++)
            {
                // if(v[i] == "") continue;
                for(int j = i + 1; j < (int)v.size(); j++)
                {
                    // if(v[j] == "") continue;
                    if(v[i] == string(v[j].rbegin(), v[j].rend()))
                    {
                        // v[i] = "";
                        // v[j] = "";
                        cnt += 2;
                        break;
                    }
                }
            }
        }
        
        
                   
         cout << "#" << t << " " << cnt * m << "\n";
    }
    return 0;
}
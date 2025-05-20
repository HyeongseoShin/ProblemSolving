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
        vector<string> v;
 
        for(int i = 0; i < 5; i++)
        {
            string s;
            cin >> s;
            v.push_back(s);
             
        }
 
        string ans = "";
 
        for(int i = 0; i < 15; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                if((int)v[j].size() <= i) continue;
                ans += v[j][i];
            }
        }
 
        cout << "#" << t << " " << ans << "\n";
    }
 
    return 0;
}
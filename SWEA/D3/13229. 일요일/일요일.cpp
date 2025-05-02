#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int testCase;
    cin >> testCase;
    
    unordered_map<string, int> um;

    um["SAT"] = 1;
    um["FRI"] = 2;
    um["THU"] = 3;
    um["WED"] = 4;
    um["TUE"] = 5;
    um["MON"] = 6;
    um["SUN"] = 7;
    
    for(int t = 1; t <= testCase; t++)
    {
        string s;
        cin >>  s;
        
        cout << "#" << t << " " << um[s] << "\n";
    }
    return 0;
}
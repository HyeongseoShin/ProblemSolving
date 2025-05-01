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
        
        int n = stoi(s);
        int k = 2;
        
        string kn = to_string(n * k);
        
        bool isPossible = false;
        while((int)kn.length() == (int)s.length())
        {
            sort(s.begin(), s.end());
            sort(kn.begin(), kn.end());
            
            if(s == kn)
            {
                isPossible = true;
                break;
            }
            
            kn = to_string(n * ++k);
        }
        
        cout << "#" << t << " ";
		if(isPossible) cout << "possible\n";
        else cout << "impossible\n";


    }
    return 0;
}
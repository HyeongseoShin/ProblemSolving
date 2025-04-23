#include <bits/stdc++.h>

using namespace std;

bool IsPalindrome(string str)
{
    
    int n = (int)str.length();
    
    string l;
    string r;
    
    if(n % 2 == 1)
    {
        l = str.substr(0, (n-1)/2);
        r = str.substr(n/2 + 1, (n-1)/2);
    }
    else
    {
        l = str.substr(0, n/2);
        r = str.substr(n/2, n/2);
    }
    
    if(l != r) return false;
    else return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int test;
    cin >> test;
    
    for(int t = 1; t <= test; t++)
    {
        string s;
        cin >> s;
        
		bool result = IsPalindrome(s);
        
        cout << "#" << t << " ";
        if(result) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
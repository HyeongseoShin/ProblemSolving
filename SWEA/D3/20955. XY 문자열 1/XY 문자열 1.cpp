#include <bits/stdc++.h>

using namespace std;

bool isPossible = false;
string s;
string e;
        
void GetAns(string str)
{
    if(str.length() == s.length())
    {
        if(str == s) isPossible = true;                
        return;
    }
    
    int last = (int)str.length() - 1;
	if(str[last] == 'X') GetAns(str.erase(last));
    else
    {
        str.erase(last);
        reverse(str.begin(), str.end());
        GetAns(str);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    
	for(int test = 1; test <= t; test++)
    {
        cin >> s >> e;
        
        isPossible = false;
        GetAns(e);
        
        cout << "#" << test;
        if(isPossible) cout << " Yes\n";
        else cout << " No\n";
    }
    

    

    
    
    return 0;
}
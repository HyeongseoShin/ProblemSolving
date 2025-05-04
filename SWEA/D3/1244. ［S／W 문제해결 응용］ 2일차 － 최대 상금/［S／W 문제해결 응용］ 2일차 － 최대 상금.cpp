#include <bits/stdc++.h>

using namespace std;

int ans;
string s;
int cnt;

void GetAns(int idx, int curCnt)
{
    if(curCnt == cnt)
    {
		ans = max(ans, stoi(s));
		return ;
    }
    
    for(int i = idx; i < (int)s.length() - 1; i++)
    {
        for(int j = i + 1; j < (int)s.length(); j++)
        {
            swap(s[i], s[j]);
            GetAns(i, curCnt + 1);
            swap(s[i], s[j]);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int testCase;
    cin >> testCase;
    
    for(int t = 1; t <= testCase; t++)
    {
        cin >> s >> cnt;
        
        ans = 0;
        
        if(cnt > (int)s.length()) cnt = (int)s.length();
        GetAns(0, 0);
        
        cout << "#" << t << " " << ans << "\n";
    }
    return 0;
}
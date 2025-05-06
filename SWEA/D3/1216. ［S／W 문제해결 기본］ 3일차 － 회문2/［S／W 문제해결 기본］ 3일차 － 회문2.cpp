#include <bits/stdc++.h>

using namespace std;

int GetMaxLenPalindrome(string target)
{
    int ret = 1;
    
    // 홀수 길이 문자의 팰린드롬 검사
    for(int i = 0; i < 100; i++)
    {
        int l = i;
        int r = i;
        
        while(l >= 0 && r < 100 & target[l] == target[r])
        {
            ret = max(ret, r - l + 1);
            l--;
            r++;
        }
        
    }
    
    // 짝수 길이 문자의 팰린드롬 검사
    for(int i = 0; i < 99; i++)
    {
        int l = i;
        int r = i + 1;
        
        while(l >= 0 && r < 100 & target[l] == target[r])
        {
            ret = max(ret, r - l + 1);
            l--;
            r++;
        }
    }
    
    return ret;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for(int t = 1; t <= 10; t++)
    {
        int n;
        cin >> n;
        
        vector<string> v;
        
        for(int i = 0; i < 100; i++)
        {
            string s;
            cin >> s;
            v.push_back(s);
        }
        
        int ans = 1;
        
        // 가로 검사
        for(auto s : v)
        {
            ans = max(ans, GetMaxLenPalindrome(s));
        }
        
        // 세로 검사
        
        for(int i = 0; i < 100; i++)
        {
            string tmp;
            for(int j = 0; j < 100; j++)
            {
                tmp += v[j][i];
            }
            
            ans = max(ans, GetMaxLenPalindrome(tmp));
        }
        
        cout << "#" << n << " " << ans << "\n";
    }
    return 0;
}
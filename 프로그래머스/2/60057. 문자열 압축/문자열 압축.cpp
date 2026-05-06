#include <bits/stdc++.h>

using namespace std;

int ans = 0;
int solution(string s) {
    ans = (int)s.length();
    
    // 압축 단위 최대 s.length() / 2
    for(int len = 1; len <= (int)s.length() / 2; len++)
    {
        
        string cur = s.substr(0, len);
        string result = "";
        int cnt = 1;
        int idx = len;
        
        while(idx < (int)s.length())
        {
            while(s.substr(idx, len) == cur)
            {
                cnt++;
                idx += len;
            }
            
            // cout << "cur: " << cur << " s.substr: " << s.substr(idx, len) << " idx: " << idx << " cnt: " << cnt << "\n";
            
            if(cnt > 1) result += to_string(cnt);
            result += cur;
            
            cur = s.substr(idx, len);
            cnt = 1;
            idx += len;
        }
        
        result += cur;
        // cout << "result: " << result << "\n\n";
        ans = min(ans, (int)result.length());
    }
    return ans;
}
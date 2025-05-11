#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> um;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int testCase;
    cin >> testCase;
    
    um["0001101"] = 0;
    um["0011001"] = 1;
    um["0010011"] = 2;
    um["0111101"] = 3;
    um["0100011"] = 4;
    um["0110001"] = 5;
    um["0101111"] = 6;
    um["0111011"] = 7;
    um["0110111"] = 8;
    um["0001011"] = 9;
    
    for(int t = 1; t <= testCase; t++)
    {
        int n, m;
        cin >> n >> m;
        
        string target;
        
		for(int i = 0; i < n; i++)
		{
            string s;
            cin >> s;
            
			if(s.find('1') == string::npos) continue;
               
           target = s;
        }
        
        int idx = 0;
        while(true)
        {
            if(target.find('1', 56 + idx) == string::npos) break;
            idx++;
        }
        
        int cnt = 0;
        int evenCnt = 0;
        int oddCnt = 0;
        int allCnt = 1;
        string tmp = "";
        
        int sum = 0;
        for(int i = idx; i <= idx + 56; i++)
        {
			if(cnt < 7)
            {
                tmp += target[i];
                cnt++;
            }
            
            if(cnt == 7)
            {
                if(allCnt % 2 == 1) oddCnt += um[tmp];
                else evenCnt += um[tmp];
                
                sum += um[tmp];
                
                // cout << "tmp: " << tmp << " oddCnt: " << oddCnt << " evenCnt: " << evenCnt << "\n";

                cnt = 0;
                allCnt++;
                tmp = "";
            }

        }
        
        int ans = oddCnt * 3 + evenCnt;

        // cout << "ans: " << ans << " sum: " << sum << "\n";
        if(ans % 10 != 0) sum = 0;
        
        cout << "#" << t << " " << sum << "\n";;
        
    }
    return 0;
}
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
        int days[7];
        int n;
        
        cin >> n;
        
        vector<int> st;
        
        for(int i = 0; i < 7; i++)
        {
            cin >> days[i];
            if(days[i] == 1) st.push_back(i);
        }
        
        int ans = INT_MAX;
        for(int i = 0; i < (int)st.size(); i++)
        {
            int curSt = st[i];
            
            int cnt = 0;
        	int tmp = 0;

            while(cnt < n)
            {
                cnt += days[curSt];
                curSt = (curSt + 1) % 7;
                tmp++;
            }
            
            ans = min(ans, tmp);
        }
        
        cout << "#" << t << " " << ans << "\n";
        
    }
    return 0;
}
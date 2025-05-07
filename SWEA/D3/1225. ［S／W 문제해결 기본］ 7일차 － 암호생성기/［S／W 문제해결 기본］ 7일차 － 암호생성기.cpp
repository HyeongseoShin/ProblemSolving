#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    
    for(int t = 1; t <= 10; t++)
    {
        int n;
        cin >> n;
        
        deque<int> dq;
        
        for(int i = 0; i < 8; i++)
        {
            int x;
            cin >> x;
            dq.push_back(x);
        }
        
        int cnt = 1;
        
        
        while(true)
        {
            int cur = dq.front();
            dq.pop_front();
            
            cur -= cnt;
            
            if(cur < 0) cur = 0;
            dq.push_back(cur);
            
            if(cur == 0) break;
            
			cnt++;
            if(cnt > 5) cnt = 1;
            

        }
        
        
        cout << "#" << n << " ";
        
        
        while(!dq.empty())
        {
            cout << dq.front() << " ";
            dq.pop_front();
        }
        cout << "\n";
    }
    return 0;
}
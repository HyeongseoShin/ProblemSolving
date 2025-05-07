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
        int n, m, k;
        
        cin >> n >> m >> k;
        
		priority_queue<int, vector<int>, greater<>> pq;
        
        for(int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            pq.push(x);
        }
        
        int cnt = 0;
        int curTime = 0;
        int makeTime = 0;
        
        bool isPossible = true;
        while(!pq.empty())
        {
            // cout << "curTime: " << curTime << " pq.top() : " << pq.top() << " cnt: " << cnt << "\n";
            while(!pq.empty() && curTime == pq.top())
            {
                pq.pop();
                cnt--;
                if(cnt < 0)
                {
                    isPossible = false;
                    break;
                }
            }
            
            if(!isPossible) break;
            
            curTime++;
            makeTime++;
            
            if(makeTime == m)
            {
                cnt += k;
                makeTime = 0;
            }
        }
        
        cout << "#" << t << " ";
        if(isPossible) cout << "Possible\n";
        else cout << "Impossible\n";
        
    }
    return 0;
}
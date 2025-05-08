#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll ans = 1000000000LL * 100000LL;

ll solution(int n, vector<int> times) {
    int m = (int)times.size();

    ll st = 0;
    ll en = 1000000000LL * 100000LL;
    ll mid = (st + en) / 2;
    
    while(st <= en)
    {
        mid = (st + en) / 2;
        ll cnt = 0;
        for(int i = 0; i < m ;i++)
        {
            cnt += (mid / times[i]);
        }
        
        if(cnt >= n)
        {
            ans = min(ans, mid);
            en = mid - 1;
        }
        else st = mid + 1;
    }
    
    // cout << "st: " << st << " mid: " << mid << " en: " << en << "\n";
    
    return ans;
}
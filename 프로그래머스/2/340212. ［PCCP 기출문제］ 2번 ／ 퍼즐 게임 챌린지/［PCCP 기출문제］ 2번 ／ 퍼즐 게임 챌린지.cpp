#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int ans = 0;
    int n = (int)diffs.size();
    long long curTime = 0;
    
    int st = 1;
    int en = 0;
    
    for(int i = 0; i < n; i++)
    {
        en = max(en, diffs[i]);
    }
    
    ans = (st + en) / 2;
    
    while(st < ans)
    {
        curTime = 0;
        for(int i = 0; i < n; i++)
        {
            if(diffs[i] <= ans || i == 0) curTime += times[i];
            
            else curTime += (diffs[i] - ans) * (times[i-1] + times[i]) + times[i];
            
            if(curTime > limit) break;
        }
        
        // 이분탐색으로 ans 업데이트
        if(curTime <= limit) en = ans;
        
        else st = ans;
        
        cout << "curTime: " << curTime << " ans: " << ans << "\n";
        
        ans = (st + en) / 2;
        
    }
    
    if(ans != 1) ans = en;
    
    
    return ans;
}
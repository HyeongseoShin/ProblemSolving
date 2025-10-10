#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int remainD = 0; // 남은 배달 양
int remainP = 0; // 남은 수거 양

int lastD = -1; // 배달 남은 마지막 집
int lastP = -1; // 수거 남은 마지막 집

ll solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    ll answer = 0;
    
    for(int i = 0; i < n; i++)
    {
        if(deliveries[i] > 0) lastD = i;
        if(pickups[i] > 0) lastP = i;
        
        remainD += deliveries[i];
        remainP += pickups[i];
    }
    
    while(remainD > 0 || remainP > 0)
    {
        int cur = min(remainD, cap); // 배달 남은 양 or cap 중 더 작은 값 싣고 출발
        
        int curPos = lastD;
        answer += (curPos + 1);
        
        // 배달
        while(cur > 0 && lastD >= 0)
        {
            if(deliveries[lastD] >= cur)
            {
                deliveries[lastD] -= cur;
                remainD -= cur;
                cur = 0;
            }
            else
            {
                cur -= deliveries[lastD];
                remainD -= deliveries[lastD];
                deliveries[lastD] = 0;
            }
            
            while(lastD >= 0 && deliveries[lastD] == 0) lastD--;
            
        }
        
        // 수거
        answer += abs(curPos - lastP);
        answer += (lastP + 1);
        
        while(cur < cap && lastP >= 0)
        {
            // 현재 장소에서 모두 수거 가능하다면
            if(pickups[lastP] + cur <= cap)
            {
                cur += pickups[lastP];
                remainP -= pickups[lastP];
                pickups[lastP] = 0;
            }
            
            // 현재 장소에서 조금만 수거 가능하다면
            else
            {
                pickups[lastP] -= (cap - cur);
                remainP -= (cap - cur);
                cur = cap;
            }
            
            while(lastP >= 0 && pickups[lastP] == 0) lastP--;
        }
            
    }
    return answer;
}
#include <bits/stdc++.h>

using namespace std;

#define MAX 1000000000

// bool isRemoved[50000];

int solution(int distance, vector<int> rocks, int n) {
    int ans = 0;
    
    int m = (int)rocks.size();
    
    sort(rocks.begin(), rocks.end());
    
    // 이분 탐색 변수 : 각 바위 사이의 최소 거리
    int st = 0;
    int en = MAX;
    int mid;
    
    while(st <= en)
    {
        mid = st + (en - st) / 2;
        
        int prev = 0;
        int cnt = 0;
        // 각 바위 사이의 최소 거리가 현재 최소 거리보다 짧으면 해당 바위 삭제
        for(int i = 0; i < m; i++)
        {
            if(rocks[i] - prev < mid)
            {
                cnt++;
            }
            else
            {
                prev = rocks[i];
            }
        }
        
        // 마지막 바위 검사
        if(distance - prev < mid) cnt++;
        
        // cout << "st: " << st << " mid: " << mid << " en: " << en << " cnt: " << cnt << "\n";
        
        if(cnt <= n)
        {
            ans = max(ans, mid);
            st = mid + 1;
        }
        
        else
        {
            en = mid - 1;
        }
    }
    
    return ans;
}
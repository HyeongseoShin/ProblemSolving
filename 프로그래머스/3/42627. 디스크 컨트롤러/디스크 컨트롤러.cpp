#include <bits/stdc++.h>

using namespace std;

// 작업 시간 짧은 순으로 정렬
struct cmp
{
  bool operator()(pair<int, int> A, pair<int, int> B)
  {
      return A.second > B.second;
  }
};

int solution(vector<vector<int>> jobs) {
    int ans = 0;
    int n = (int)jobs.size();
    
    // 요청 시간 순으로 정렬
    sort(jobs.begin(), jobs.end());
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    
    int curTime = 0;
    int idx = 0;
    
    while(true)
    {
        // 모든 작업 끝났을 때
        if(idx >= n && pq.empty()) break;
        
        // 현재 시간보다 요청 시간이 빠른 일들 pq에 삽입
        while(idx < n && jobs[idx][0] <= curTime)
        {
            pq.push({jobs[idx][0], jobs[idx][1]});
            idx++;
            
        }
        
        // 대기 중인 작업이 있으면
        if(!pq.empty())
        {
            ans += (curTime - pq.top().first + pq.top().second);
            curTime += pq.top().second;
            pq.pop();
        }
        
        else
        {
            curTime = jobs[idx][0];
        }
    }
    
    return ans / n;
}
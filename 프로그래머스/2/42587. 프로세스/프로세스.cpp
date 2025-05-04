#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int n = (int)priorities.size();
    
    priority_queue<int> pq(priorities.begin(), priorities.end());
    queue<pair<int, int>> q;
    
    for(int i = 0; i < n; i++)
    {
        q.push({priorities[i], i});
    }
    
    while(!q.empty())
    {
        auto [curPriority, idx] = q.front();
        q.pop();
        
        if(curPriority == pq.top())
        {
            pq.pop();
            answer++;
            
            if(idx == location) return answer;
        }
        else
        {
            q.push({curPriority, idx});
        }
    }
    
    return answer;
}
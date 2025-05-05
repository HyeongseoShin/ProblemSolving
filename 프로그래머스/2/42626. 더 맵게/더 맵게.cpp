#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<>> pq;
    
    for(int i = 0; i < (int)scoville.size(); i++)
    {
        pq.push(scoville[i]);
    }
    
    while(pq.size() >= 2)
    {
        int first = pq.top();
        pq.pop();
        
        int second = pq.top();
        pq.pop();
        
        if(first >= K && second >= K) continue;
        
        pq.push(first + second * 2);
        answer++;
    }
    
    if(pq.empty() || pq.top() >= K) return answer;
    else if(pq.top() < K) return -1;
    
    return answer;
}
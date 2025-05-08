#include <bits/stdc++.h>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int n = truck_weights.size();
    
    queue<int> q;
    
    int sum = 0; // 현재 다리 위에 있는 트럭 무게의 합
    
    for(int i = 0; i < n; i++)
    {        
        while(true)
        {
            // 다리가 꽉 차면 앞 차부터 빼기
            if(q.size() == bridge_length)
            {
                sum -= q.front();
                q.pop();
            }
            
            // 현재 차가 다리에 진입할 수 있으면 break
            if(sum + truck_weights[i] <= weight) break;
            
            q.push(0);
            answer++;
        }
        
        // 현재 차량 다리에 진입
        sum += truck_weights[i];
        q.push(truck_weights[i]);
        answer++;
    }
    
    
    return answer + bridge_length;
}
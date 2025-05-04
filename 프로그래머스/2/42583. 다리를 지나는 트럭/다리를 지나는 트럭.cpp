#include <bits/stdc++.h>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int n = (int)truck_weights.size();
    
    queue<int> q;
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        while(true)
        {
            if(q.size() == bridge_length)
            {
                sum -= q.front();
                q.pop();
            }
            
            if(sum + truck_weights[i] <= weight) break;
            
            q.push(0);
            answer++;
        }
        
        q.push(truck_weights[i]);
        sum += truck_weights[i];
        answer++;
    }
    return answer + bridge_length;
}
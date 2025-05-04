#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    int n = (int) progresses.size();
    vector<int> answer;
    queue<int> q;
    
    for(int i = 0; i < n; i++)
    {
        int tmp = (100 - progresses[i]) / speeds[i];
        if((100 - progresses[i]) % speeds[i] != 0) tmp++;
        
        q.push(tmp);
    }
    
    
    int cnt = 0;
    int maxVal = q.front();
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        
        if(maxVal < cur)
        {
            answer.push_back(cnt);
            maxVal = cur;
            cnt = 0;
        }
        
        cnt++;
    }
    
    answer.push_back(cnt);
    
    
    return answer;
}
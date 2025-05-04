#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int n = (int)prices.size();
    
    answer.resize(n);
    
    // <prices, 인덱스>
    stack<pair<int, int>> stk;
    
    for(int i = 0; i < n; i++)
    {
        // if(stk.empty() || stk.top() <= prices[i])
        
        while(!stk.empty() && stk.top().first > prices[i])
        {
            auto [curPrices, idx] = stk.top();
            answer[idx] = i - idx;
            stk.pop();
        }
        
        stk.push({prices[i], i});
    }
    
    while(!stk.empty())
    {
        auto [curPrices, idx] = stk.top();
        answer[idx] = (n - idx - 1);
        stk.pop();
    }
    return answer;
}
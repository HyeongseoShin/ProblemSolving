#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    deque<int> dq;
    string buff;
    
    for(string op : operations)
    {
        if(op[0] == 'I')
        {
            int num = stoi(op.substr(2, (int)op.length() - 2));
            dq.push_back(num);
        }
        
        
        else if(op[2] == '1' && !dq.empty()) dq.pop_back();
        else if(!dq.empty()) dq.pop_front();
        
        sort(dq.begin(), dq.end());
    }
    
    if(!dq.empty())
    {
        answer.push_back(dq.back());
        answer.push_back(dq.front());
    }
    
    else
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    
    return answer;
}
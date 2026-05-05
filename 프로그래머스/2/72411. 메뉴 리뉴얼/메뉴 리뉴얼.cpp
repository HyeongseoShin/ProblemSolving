#include <bits/stdc++.h>

using namespace std;

int n;
unordered_map<string, int> candidates;

void setCandidates(string cur, string order, int idx, vector<int> &course)
{
    if(find(course.begin(), course.end(), (int)cur.length()) != course.end())
    {
        candidates[cur]++;
    }
    
    if(idx > (int)order.length()) return;
    
    for(int i = idx; i < (int)order.length(); i++)
    {
        setCandidates(cur + order[i], order, i+1, course);
    }
}


vector<string> solution(vector<string> orders, vector<int> course) {
    
    for(auto order : orders)
    {
        sort(order.begin(), order.end());
        setCandidates("", order, 0, course);    
    }
    
    vector<string> answer;
    
    int maxCnt[10];
    memset(maxCnt, 0, sizeof(maxCnt));
    
    for(auto [candidate, cnt] : candidates)
    {
        if(cnt >= 2) maxCnt[(int)candidate.length()] = max(maxCnt[(int)candidate.length()], cnt);
    }
    
    for(auto [candidate, cnt] : candidates)
    {
        if(cnt == maxCnt[(int)candidate.length()])
        {
            cout << candidate << " " << cnt << "\n";
            answer.push_back(candidate);
        }
    }
        
    sort(answer.begin(), answer.end());    
    
    return answer;
}
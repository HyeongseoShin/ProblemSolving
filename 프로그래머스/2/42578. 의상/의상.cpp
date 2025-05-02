#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    int n = (int)clothes.size();
    unordered_map<string ,int> um;
    
    for(int i = 0; i < n; i++)
    {
        um[clothes[i][1]]++;
    }
    
    
    for(auto [s, cnt] : um)
    {
        answer *= (cnt + 1);
        // cout << "answer: " << answer << "\n";
    }
    
    answer -= 1;
    return answer;
}
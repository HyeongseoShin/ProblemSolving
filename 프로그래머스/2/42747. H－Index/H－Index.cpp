#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end(), greater<>());
    
    int n = (int)citations.size();
    
    for(int i = 0; i < n; i++)
    {
        if(citations[i] > i) answer++;
        else return answer;
    }
    
    return answer;
}
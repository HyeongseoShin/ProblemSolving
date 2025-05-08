#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    int st = 0;
    int en = (int)people.size() - 1;
    
    sort(people.begin(), people.end());
    while(st <= en)
    {
        if(people[st] + people[en] <= limit)
        {
            st++;
        }
        
        en--;
        answer++;
        
    }
    return answer;
}
#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> people, int limit) {
    
    int ans = 0;
    int n = (int)people.size();
    
    sort(people.begin(), people.end());
    
    int st = 0;
    int en = n - 1;
    
    while(st <= en)
    {
        if(people[st] + people[en] <= limit) st++;
        en--;
        
        ans++;
    }
    
    return ans;
}
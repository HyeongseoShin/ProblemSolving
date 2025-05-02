#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int n = (int)nums.size();
    
    unordered_map<int, int> um;
    
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        if(um.find(nums[i]) == um.end()) cnt++;
        um[nums[i]]++;
    }
    
    if(cnt < n / 2) return cnt;
    else return n / 2;
    
    
    return answer;
}
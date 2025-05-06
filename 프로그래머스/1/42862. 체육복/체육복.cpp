#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n - (int)lost.size();
    
    bool hasClothes[31];
    
    fill(hasClothes, hasClothes + 31, true);
    
    for(int i = 0; i < (int)lost.size(); i++)
    {
        hasClothes[lost[i]] = false;
    }
    
    for(int i = 0; i < (int)reserve.size(); i++)
    {
        if(!hasClothes[reserve[i]])
        {
            hasClothes[reserve[i]] = true;
            answer++;
            
            reserve.erase(reserve.begin() + i);
            i--;
        }
    }
    
    sort(reserve.begin(), reserve.end());
    
    for(int i = 0; i < (int)reserve.size(); i++)
    {
        int prev = reserve[i] - 1;
        int nxt = reserve[i] + 1;
                
        if(prev >= 1 && !hasClothes[prev])
        {
            hasClothes[prev] = true;
            answer++;
        }
        
        else if(nxt <= n && !hasClothes[nxt])
        {
            hasClothes[nxt] = true;
            answer++;
        }
    }
    
    return answer;
}
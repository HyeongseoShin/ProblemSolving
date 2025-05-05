#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int w = 0, h = 0;
    
    int n = (int)sizes.size();
    
    for(int i = 0; i < n; i++)
    {
        w = max(w, sizes[i][0]);
        h = max(h, sizes[i][1]);
    }
    
    int maxVal = max(w, h);
    int minVal = min(w, h);
    
    // cout << "maxVal: " << maxVal << " minVal: " << minVal << "\n";
    while(true)
    {
        minVal--;        
        bool isPossible = true;
        
        for(int i = 0; i < n; i++)
        {
            if((sizes[i][0] <= minVal && sizes[i][1] <= maxVal) || (sizes[i][0] <= maxVal && sizes[i][1] <= minVal)) continue;
            
            isPossible = false;
            break;
        }
        
        if(!isPossible) break;
        
        
    }
    
    return maxVal * (minVal + 1);
}
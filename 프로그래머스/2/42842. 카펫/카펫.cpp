#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> ans;
    
    int sz = brown + yellow;
    
    vector<int> w;
    vector<int> h;
    
    vector<int> yW;
    vector<int> yH;
    
    for(int i = 1; i <= sz; i++)
    {
        if(sz % i == 0)
        {
            if(sz / i < i) break;
            w.push_back(sz / i);
            h.push_back(i);
        }
    }
    
    for(int i = 1; i <= yellow; i++)
    {
        if(yellow % i == 0)
        {
            if(yellow / i < i) break;
            yW.push_back(yellow / i);
            yH.push_back(i);
        }
    }
    
    for(int i = 0; i < (int)w.size(); i++)
    {
        bool isPossible = false;
        for(int j = 0; j < (int)yW.size(); j++)
        {
            if(yW[j] + 2 <= w[i] && yH[j] + 2 <= h[i])
            {
                isPossible = true;
                break;
            }
        }
        
        if(isPossible)
        {
            ans.push_back(w[i]);
            ans.push_back(h[i]);
            break;
        }
    }
    
    return ans;
}
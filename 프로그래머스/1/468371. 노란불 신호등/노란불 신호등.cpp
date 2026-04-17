#include <bits/stdc++.h>

using namespace std;

int n;
int ans = -1;

int yCnt[10000001];

int solution(vector<vector<int>> signals) {
    n = (int)signals.size();
    
    for(int i = 0; i < n; i++)
    {
        int g = signals[i][0];
        int y = signals[i][1];
        int r = signals[i][2];
        
        int st = g + 1;
        int step = g + y + r;
        
        for(int j = st; j + y < 10000001; j += step)
        {
            yCnt[j] += 1;
            yCnt[j + y] -= 1;
        }
    }
    
    for(int i = 1; i < 10000001; i++)
    {
        yCnt[i] = yCnt[i-1] + yCnt[i];
        if(yCnt[i] == n)
        {
            ans = i;
            break;
        }
    }
    
    return ans;
}
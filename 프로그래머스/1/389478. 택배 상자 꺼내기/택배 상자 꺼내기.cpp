#include <bits/stdc++.h>

using namespace std;

int solution(int n, int w, int num) {
    int ans = 0;
    
    int cur = 1;
    int step = 1;
    int y = 1;
    int targetY = -1;
    
    while(cur <= n)
    {
        if(cur == num) targetY = y;
        if(y == targetY) ans++;
        
        y += step;
        cur++;    
        if(y > w)
        {
            y = w;
            step *= -1;
        }
        else if(y < 1)
        {
            y = 1;
            step *= -1;
        }
    }
    
    return ans;
    
    
}
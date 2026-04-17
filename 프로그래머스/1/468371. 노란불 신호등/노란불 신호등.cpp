#include <bits/stdc++.h>

using namespace std;

int n;
int ans = -1;

int Lcm = 1;

int getGcd(int a, int b)
{
    if(a == 0) return b;
    return getGcd(b % a, a);
}

int getLcm(int a, int b)
{
    return a / getGcd(a, b) * b;
}


int solution(vector<vector<int>> signals) {
    n = (int)signals.size();
    
    // 최소 공배수 구하기
    for(int i = 0; i < n; i++)
    {
        int g = signals[i][0];
        int y = signals[i][1];
        int r = signals[i][2];
        
        Lcm = getLcm(Lcm, g + y + r);
    }
    
    // 현재 시각
    for(int i = 1; i <= Lcm; i++)
    {
        bool isPossible = true;
        for(int j = 0; j < n; j++)
        {
            int g = signals[j][0];
            int y = signals[j][1];
            int r = signals[j][2];
            int cycle = g + y + r;
            
            // 현재 주기에서 위치
            int cur = (i - 1) % cycle + 1;
            
            if(!(g + 1 <= cur && cur <= g + y))
            {
                isPossible = false;
                break;
            }
        }
        
        if(isPossible)
        {
            ans = i;
            break;
        }
    }
    
    return ans;
}